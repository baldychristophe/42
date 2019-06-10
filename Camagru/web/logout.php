<?php
include ('user.php');
if (login_check() == 1)
{
	$_SESSION['message'] = "Vous devez être connecté pour vous déconnecter";
	header('location:login.php');
}
else
{
	unset($_SESSION['user']);
	$_SESSION['message'] = "Vous avez été déconnecte";
	header('location:login.php');
}
?>
