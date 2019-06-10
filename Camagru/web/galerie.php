<?php
include('user.php');
if (login_check() == 1)
{
    $_SESSION['message'] = "Vous devez être connecté pour accéder à cette page";
	header('location:login.php');
}
include('create_galerie.php');
?>

<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="theme.css">
        <link rel="stylesheet" type="text/css" href="galerie.css">
        <title>Camagru - Galerie</title>
        <link rel="shortcut icon" href="../img/logo_green.png">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.0/jquery.min.js"></script>
         <script src="galerie.js"></script>      
    </head>
    
    <body background="../img/background2.jpg">
        <header class="container">
            <a href="../index.php"><img id="header_logo" src="../img/logo2.png"></a>
            <h1>Camagru</h1>
            <h2>Galerie</h2>
        </header>
        <div id="nav">
                <ul>
                    <li><a href="montage.php">Montage</a></li>
                    <li><a href="galerie.php">Galerie</a></li>
                    <li><a href="compte.php">Mon Compte</a></li>
                    <li style="float:right"><a href="logout.php">Deconnection</a></li>
                </ul>
        </div>
        <div id="main_wrapper">
            <div id="message">
                <?php if (isset($_SESSION['message'])) {
                    echo $_SESSION['message'];} 
                    $_SESSION['message'] = "";?>
            </div>
            <?php create_galerie(); ?>
        </div>
        <footer>
            Camagru.fr All rights reserved
            <br />Christophe Baldy
        </footer>
    </body>
</html>
