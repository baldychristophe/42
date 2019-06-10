function like_montage(id) {
    $.ajax({
        url: "like_montage.php",
        type: "POST",
        data: {'id': id},
        success: function(nb_like) {
            update_like(id, nb_like);
        },
        error: function() {
            alert("Une erreur est survenue");
        }
    });
}
function update_like(id, nb_like) {
    var td = document.getElementById(id);
    var button = td.getElementsByClassName("clicked")[0];
    var span = td.getElementsByClassName("nb_like")[0];
    if (button != null) {
        button.setAttribute("class", "like_button")
        span.textContent = "likes: " + nb_like;
    }
    else {
        button = td.getElementsByTagName("button")[0];
        button.setAttribute("class", "like_button clicked")
        span.textContent = "likes: " + nb_like;
    }
}