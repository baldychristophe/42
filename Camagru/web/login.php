<?php
include ('user.php');
if (login_check() == 0)
	header('location:montage.php');
else if (isset($_POST['submit']) && $_POST['submit'] == "Login")
{
    unset($_SESSION['message']);
	if ($_POST['login'] == "" || $_POST['password'] == "")
		$_SESSION['message'] = "Veuillez indiquer un login et un mot de passe";
    else if (login_is_valid($_POST['login'], $_POST['password']) === 0)
	{
		$_SESSION['user']['login'] = $_POST['login'];
		$_SESSION['user']['password'] = $_POST['password'];
		header('location:montage.php');
	}
	else if (isset($_SESSION['message']) === False)
		$_SESSION['message'] = "Identifiant et mot de passe incorrects";
}
?>
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="theme.css">
        <link rel="stylesheet" type="text/css" href="login.css">
        <title>Camagru - Login</title>
        <link rel="shortcut icon" href="../img/logo_green.png">        
    </head>
    
    <body background="../img/background2.jpg">
        <header class="container">
            <a href="../index.php"><img id="header_logo" src="../img/logo2.png"></a>
            <h1>Camagru</h1>
            <h2>Login</h2>
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
            <form method="POST" action="login.php">
                <table class="signin">
                    <tr>
                        <td class="label">Identifiant: </td>
                        <td class="int"><input type="text" name="login" /></td>
                    </tr>
                    <tr>
                        <td class="label">Mot de passe: </td>
                        <td class="int"><input type="password" name="password" /></td>
                    </tr>
                    <tr>
                        <td class="int" colspan=2><input type="submit" name="submit" value="Login" /></td>
                    </tr>
                    <tr>
                        <td><a href="signin.php"> Inscription</a></td>
                        <td><a href="forget.php"> Mot de passe oublié ?</a></td>
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
