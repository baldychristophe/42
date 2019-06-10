navigator.getUserMedia = navigator.getUserMedia || 
    navigator.webkitGetUserMedia || 
    navigator.mozGetUserMedia || 
    navigator.msGetUserMedia || 
    navigator.oGetUserMedia;

function change_view(to_hide, to_display) {
    to_hide.style.display='none';
    if (to_display == div_empty) {
        to_display.style.display='table';
        document.getElementById("stop_webcam").disabled = true;
        document.getElementById("take_screenshot").disabled = true;
        document.getElementById("clear_preview").disabled = true;
        document.getElementById("save_image").disabled = true;
    }
    else if (to_display == div_video) {
        to_display.style.display='block';
        document.getElementById("stop_webcam").disabled = false;
        document.getElementById("take_screenshot").disabled = false;
        document.getElementById("clear_preview").disabled = true;
        document.getElementById("save_image").disabled = true;
    }
    else if (to_display == div_img) {
        to_display.style.display='block';
        document.getElementById("stop_webcam").disabled = true;
        document.getElementById("take_screenshot").disabled = true;
        document.getElementById("clear_preview").disabled = false;
        document.getElementById("save_image").disabled = false;
    }
}

function start_webcam(){
    if (navigator.getUserMedia) {
        navigator.getUserMedia({video: true}, handleVideo, videoError);
    }
    function handleVideo(stream) {
        video.src = window.URL.createObjectURL(stream);
        video.play();
        change_view(div_empty, div_video);
        localStream = stream;
    }
    function videoError(e) {
        alert ("Error: Your browser does not support this process !");
    }
}
function stop_webcam(){
    localStream.getTracks()[0].stop();
    change_view(div_video, div_empty);
}
function screenshot() {
    localStream.getTracks()[0].stop();
    canvas.setAttribute('width', video.videoWidth);
    canvas.setAttribute('height', video.videoHeight);
    ctx.drawImage(video, 0, 0);
    document.querySelector('#preview').src = canvas.toDataURL('image/png');
    change_view(div_video, div_img);
}
function clear_preview() {
    document.querySelector('#preview').src = "";
    document.querySelector('#upload_img').value = ""
    change_view(div_img, div_empty);
}
function save_image() {
    $.post("save_image.php", {
        fond: canvas.toDataURL('image/png'),
        ft_name: "save_webcam",
        }, function() {update_side();}
    );
    clear_preview();

}
function preview_img(event) {
    var output = document.getElementById('preview');
    output.src = URL.createObjectURL(event.target.files[0]);
    change_view(div_empty, div_img);
    output.onload = function(){
        canvas.width = output.width;
        canvas.height = output.height;
        ctx.drawImage(output, 0, 0, output.width, output.height);
    };
}
function upload_img(e) {
	e.preventDefault();
    save_image();
}
function update_side() {
    var side = document.getElementById("side");
    while (side.firstChild) {
        side.removeChild(side.firstChild);
    }    
    $.ajax({
        url: "montage_side.php",
        type: "POST",
        success: function(data) {
            var arr = JSON.parse(data);
            var i = 0;
            while(i < arr.length) {
                newSideImg = createSideImg(arr[i]);
                side.insertBefore(newSideImg, side.firstChild);
                i++;
            }        
        },
    });
}
function createSideImg(src) {
    var div = document.createElement("div")
    div.setAttribute("class", "side_div_wr");
    var link = document.createElement("a");
    link.href = "image.php?id=" + src['id'];
    div.appendChild(link);
    var img = document.createElement("img");
    img.src = src['img'];
    img.setAttribute("class", "side_img");
    link.appendChild(img);
    var info = document.createElement("div");
    info.setAttribute("class", "side_info_div");
    info.innerText += "idPhoto: " + src['id'];
    div.appendChild(info);
    return (div);
}