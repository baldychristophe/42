<?php
include ('user.php');
if (login_check() == 1)
{
	$_SESSION['message'] = "Vous devez être connecté pour supprimer votre compte";
	header('location:login.php');
}
delete_account($_SESSION['user']['login'], $_SESSION['user']['password']);
unset($_SESSION['user']);
$_SESSION['message'] = "Vous compte a été supprimé";
header('location:login.php');
?>