<?php
include ('user.php');
if (login_check() == 0)
	header('location:montage.php');
if (isset($_POST['submit']) && $_POST['submit'] == "Inscription" && $_POST['login'] != "" &&
$_POST['password'] != "" && $_POST['email'] != "")
{
	unset($_SESSION['message']);
	if (strlen($_POST['password']) < 4)
		$_SESSION['message'] = "Mot de passe trop court ! (4 caracteres minimum)";
	else if (preg_match('/[A-Z]/', $_POST['password']) != 1 ||
		preg_match('/[a-z]/', $_POST['password']) != 1 ||
		preg_match('/[0-9]/', $_POST['password']) != 1)
		$_SESSION['message'] = "Mot de passe incorrect ! Il doit contenir au moins une lettre majuscule, une lettre minuscule et un chiffre";
	else if (signin($_POST['login'], $_POST['password'], $_POST['email']) == 0)
		header('location:montage.php');
	else if (isset($_SESSION['message']) === False)
		$_SESSION['message'] = "Champs incorrects ! Veuillez réessayer";
}
else 
    $_SESSION['message'] = "Veuillez remplir tous les champs";
?>
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="theme.css">
        <link rel="stylesheet" type="text/css" href="signin.css">
        <title>Camagru - Login</title>
        <link rel="shortcut icon" href="../img/logo_green.png">        
    </head>
    
    <body background="../img/background2.jpg">
        <header class="container">
            <a href="../index.php"><img id="header_logo" src="../img/logo2.png"></a>
            <h1>Camagru</h1>
            <h2>Inscription</h2>
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
                <?php if (isset($_SESSION['message'])) {echo $_SESSION['message'];} ?>
            </div>
            <form method="POST" action="signin.php">
                <table class="signin">
                    <tr>
                        <td class="int">Identifiant: </td>
                        <td><input type="text" name="login" /></td>
                    </tr>
                    <tr>
                        <td class="int">Email: </td>
                        <td><input type="text" name="email" /></td>
                    </tr>
                    <tr>
                        <td class="int">Mot de passe: </td>
                        <td><input type="password" name="password" /></td>
                    </tr>
                    <tr>
                        <td class="int" colspan=2><input type="submit" name="submit" value="Inscription" /></td>
                    </tr>
                </table>
            </form>
        </div>
        <footer>
            Camagru.fr All rights reserved <br />
            Christophe Baldy
        </footer>
    </body>
</html>
