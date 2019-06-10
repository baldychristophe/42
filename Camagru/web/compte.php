<?php
include('user.php');
if (login_check() == 1)
{
	$_SESSION['message'] = "Vous devez être connecté pour accéder à cette page";
	header('location:login.php');
}
if (login_is_confirmed($_SESSION['user']['login']) == 0)
	$_SESSION['user']['confirmation'] = "OUI";
else
	$_SESSION['user']['confirmation'] = "NON";
?>

<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="theme.css">
        <link rel="stylesheet" type="text/css" href="compte.css">
        <title>Camagru - Mon Compte</title>
        <link rel="shortcut icon" href="../img/logo_green.png">        
    </head>
    
    <body background="../img/background2.jpg">
        <header class="container">
            <a href="../index.php"><img id="header_logo" src="../img/logo2.png"></a>
            <h1>Camagru</h1>
            <h2>Mon Compte</h2>
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
            <div id="bienvenue">
                    <?php if (isset($_SESSION['user']['login'])) {echo "Bienvenue " . $_SESSION['user']['login'];} ?>
            </div>
            <table class="compte">
                <tr>
                    <td>Email Confirmé: </td><td><?php echo ($_SESSION['user']['confirmation']); ?><td>
                </tr>
                <tr>           
                    <td>Modifier mon mot de passe: </td><td><a href="password.php"><button type="button">modifier</button></a></td>
                </tr>
                <tr>
                    <td>Supprimer mon compte: </td><td><a href="delete.php"><button type="button">Supprimer</button></a></td>
                </tr>
            </table>
        </div>
        <footer>
            Camagru.fr All rights reserved
            <br />Christophe Baldy
        </footer>
    </body>
</html>
