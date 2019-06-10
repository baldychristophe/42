<?php
include ('user.php');
if (login_check() == 1)
	header('location:login.php');
else if (isset($_POST['submit']) && $_POST['submit'] == "Modify")
{
    unset($_SESSION['message']);
	if ($_POST['old'] == "" || $_POST['password'] == "" || $_POST['again'] == "")
		$_SESSION['message'] = "Veuillez renseigner tous les champs";
    else if ($_POST['old'] != $_SESSION['user']['password'])
        $_SESSION['message'] = "Mauvais mot de passe ! Votre mot de passe n'a pas été modifié";
    else if ($_POST['password'] != $_POST['again'])
		$_SESSION['message'] = "Le mot de passe de confirmation est incorrect";
    else if (strlen($_POST['password']) < 4)
		$_SESSION['message'] = "Nouveau mot de passe trop court";
    else if ($_POST['password'] == $_SESSION['user']['password'])
		$_SESSION['message'] = "Vous devez indiquer un nouveau mot de passe différent de l'ancien ! OMG";
    else 
    {
        update_password($_SESSION['user']['login'], $_POST['password']);
        $_SESSION['user']['password'] = $_POST['password'];
        header('location:compte.php');
    }
}
?>
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="theme.css">
        <link rel="stylesheet" type="text/css" href="password.css">
        <title>Camagru - Login</title>
        <link rel="shortcut icon" href="../img/logo_green.png">        
    </head>
    
    <body background="../img/background2.jpg">
        <header class="container">
            <a href="../index.php"><img id="header_logo" src="../img/logo2.png"></a>
            <h1>Camagru</h1>
            <h2>Mot de passe</h2>
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
            <form method="POST" action="password.php">
                <table id="password">
                    <tr>
                        <td>Ancien mot de passe: </td>
                        <td><input type="password" name="old" /></td>
                    </tr>
                    <tr>
                        <td>Nouveau mot de passe: </td>
                        <td><input type="password" name="password" /></td>
                    </tr>
                    <tr>
                        <td>Confirmer le nouveau mot de passe: </td>
                        <td><input type="password" name="again" /></td>
                    </tr>
                    <tr>
                        <td class="int" colspan=2><input type="submit" name="submit" value="Modify" /></td>
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