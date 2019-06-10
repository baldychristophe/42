<?php
include('user.php');

if (empty($_GET['login']) || empty($_GET['code']))
{
	$_SESSION['message'] = "URL invalide";
	die(1);
}
else if (is_valid_confirmation_code($_GET['login'], $_GET['code']) == 1)
	$_SESSION['message'] = "Code de confirmation invalide !";
else
	$_SESSION['message'] = "Merci ".$_GET['login'].".\nVotre Compte est maintenant verifie.";

?>
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="theme.css">
        <link rel="stylesheet" type="text/css" href="montage.css">
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
                <?php if (isset($_SESSION['message'])) {echo $_SESSION['message'];} ?>
            </div>
        </div>
        <footer>
            Camagru.fr All rights reserved
            <br />Christophe Baldy
        </footer>
    </body>
</html>
