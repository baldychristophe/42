<?php
include('user.php');

if (login_check() == 1)
{
    $_SESSION['message'] = "Vous devez être connecté pour accéder à cette page";
	header('location:login.php');
}
else if (login_is_confirmed($_SESSION['user']['login']) == 1)
	$_SESSION['message'] = "Veuillez confirmer votre mail pour pouvoir faire un montage";
else
	unset($_SESSION['message']);
?>
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="theme.css">
        <link rel="stylesheet" type="text/css" href="montage.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.0/jquery.min.js"></script>
        <script src="montage.js"></script>
        <title>Camagru - Montage</title>
        <link rel="shortcut icon" href="../img/logo_green.png">      
    </head>
    
    <body background="../img/background2.jpg">
        <header class="container">
            <a href="../index.php"><img id="header_logo" src="../img/logo2.png"></a>
            <h1>Camagru</h1>
            <h2>Montage</h2>
        </header>
        <div id="nav">
                <ul>
                    <li><a href="montage.php">Montage</a></li>
                    <li><a href="galerie.php">Galerie</a></li>
                    <li><a href="compte.php">Mon Compte</a></li>
                    <li style="float: right"><a href="logout.php">Deconnection</a></li>
                </ul>
        </div>
        <div id="main_wrapper">
            <div id="message">
                <?php if (isset($_SESSION['message'])) {echo $_SESSION['message'];unset($_SESSION['message']);} ?>
            </div>
            <div id="main">
                <div id="container">
                    <div id="div_video"><video id="videoElement"></video></div>
                    <div id="div_img"><img id="preview" src=""></div>
                    <div id="div_empty">
                        <div class="button_line">
                            <button id="start_webcam" type="button" onclick="start_webcam()"> Démarrer la Webcam </button>
                            <form id="upload_img_form">
                                <input type="file" id="upload_img" name="uploaded_img" accept="image/*" onchange="preview_img(event)"/>
                            </form>
                        </div>                        
                    </div>
                </div>
                <div class="button_line2">
                    <button id="stop_webcam" type="button" onclick="stop_webcam()" disabled="true"> Arrêter Webcam </button>
                    <button id="take_screenshot" type="button" onclick="screenshot()" disabled="true"> Prendre Photo </button>
                    <button id="clear_preview" type="button" onclick="clear_preview()" disabled="true"> Supprimer image </button>
                    <button id="save_image" type="button" onclick="save_image()" disabled="true"> Enregistrer l'Image </button>
                    <canvas id="main_canvas" style="display: none;"> </canvas>
                </div>
                <img id="test" src="" />
                <button type="button" onclick="update_side()"> Update </button>                
            </div>
            <div id="side">   
            </div>
        </div>
        <footer>
            Camagru.fr All rights reserved
            <br />Christophe Baldy
        </footer>
    </body>
    <script>
        var canvas = document.querySelector('#main_canvas');
        var ctx = canvas.getContext('2d');
        var video = document.querySelector("#videoElement");
        var div_empty = document.querySelector('#div_empty');
        var div_img = document.querySelector('#div_img');
        var div_video = document.querySelector('#div_video');
        var localStream = null;
        var uploaded_img = document.querySelector('#upload_img');
        document.getElementById('upload_img_form').addEventListener('submit', upload_img, false);
        update_side();    
    </script>
</html>