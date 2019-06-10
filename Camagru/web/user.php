<?php

session_start();

function login_is_valid($login, $password)
{
	include ('../config/database.php');
	$hash = hash('whirlpool', $password);
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT login, groupe FROM users WHERE login = ? AND password = ?;");
		$stmt->bindValue(1, $login, PDO::PARAM_STR);
		$stmt->bindValue(2, $hash, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetch(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return (1);
	}
	if ($result !== False)
		return (0);
	else
		return (1);
}

function login_insert_new($login, $password, $email)
{
	include ('../config/database.php');
	$hash = hash('whirlpool', $password);
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("INSERT INTO users (login, password, email) VALUES (?, ?, ?);");
		$stmt->bindValue(1, $login, PDO::PARAM_STR);
		$stmt->bindValue(2, $hash, PDO::PARAM_STR);
		$stmt->bindValue(3, $email, PDO::PARAM_STR);
		$stmt->execute();
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return (1);
	}
	return (0);
}

function login_exist($login, $email)
{
	include ('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT login FROM users WHERE login = ? OR email = ?;");
		$stmt->bindValue(1, $login, PDO::PARAM_STR);
		$stmt->bindValue(2, $email, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetch(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return (1);
	}
	if ($result !== False)
		return (0);
	else
		return (1);
}

function signin($login, $password, $email)
{
	if (login_exist($login, $email) === 0)
	{
		$_SESSION['message'] = "Identifiant ou adresse mail deja utilises";
		return (1);
	}
	else if (!filter_var($email, FILTER_VALIDATE_EMAIL))
	{
		$_SESSION['message'] = "Adresse mail invalide";
		return (1);
	}
	else if (login_insert_new($login, $password, $email) == 0)
	{
		$_SESSION['user']['login'] = $login;
		$_SESSION['user']['password'] = $password;
		send_confirmation_mail($login);
		return (0);
	}
	return (1);
}

function login_check()
{
	if (isset($_SESSION['user']) === False)
		return (1);
	else if (login_is_valid($_SESSION['user']['login'], $_SESSION['user']['password']) == 1)
		return (1);
	return (0);
}

function login_is_confirmed($login)
{
	include ('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT login, confirmation FROM users WHERE login = ?;");
		$stmt->bindValue(1, $login, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetch(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return (1);
	}
	if ($result['confirmation'] == "yes")
		return (0);
	else
		return (1);
}

function delete_account($login, $password)
{
	include ('../config/database.php');
	$hash = hash('whirlpool', $password);
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("DELETE FROM users WHERE login = ? AND password = ?");
		$stmt->bindValue(1, $login, PDO::PARAM_STR);
		$stmt->bindValue(2, $hash, PDO::PARAM_STR);
		$stmt->execute();
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return (1);
	}
	return (0);
}

function send_confirmation_mail($login)
{
	include ('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT id, login, password, email FROM users WHERE login = ?;");
		$stmt->bindValue(1, $login, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetch(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return (1);
	}
	$hash_code = hash('whirlpool', $result['id'].$result['login'].$result['password']);
	$lien = $_SERVER['HTTP_HOST']
		.substr($_SERVER['PHP_SELF'], 0, strrpos($_SERVER['PHP_SELF'], "/"))
		."/confirmation.php?login=".$login."&code=".$hash_code."&";
	$subject = "Camagru - Confirmation de votre mail";
	$message = "
		<html>
			<body>
				Bonjour,
				<br />Merci d'avoir rejoint la grande famille de Camagru !
				<br /> La derniere etape de votre inscription consiste a verifier votre adresse 
				email en cliquant sur le lien suivant ou en le copiant dans votre navigateur: 
				<br /> <a href='".$lien."'>".$lien."</a>
			</body>
		</html>";

	$headers  = 'MIME-Version: 1.0' . "\r\n";
	$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
	$headers .= 'From: noreply <noreply@camagru.com>' . "\r\n";
	mail($result['email'], $subject, $message, $headers);
}

function is_valid_confirmation_code($login, $code)
{
	include ('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT id, login, password FROM users WHERE login = ?;");
		$stmt->bindValue(1, $login, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetch(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return (1);
	}
	$hash_code = hash('whirlpool', $result['id'].$result['login'].$result['password']);
	if ($code == $hash_code)
	{
		update_confirmation_mail($login);
		return (0);
	}
	else
		return (1);
}

function update_confirmation_mail($login)
{
	include ('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("UPDATE users SET confirmation='yes' WHERE login = ?;");
		$stmt->bindValue(1, $login, PDO::PARAM_STR);
		$stmt->execute();
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return (1);
	}
	return (0);
}

function update_password($login, $new_password)
{
	include ('../config/database.php');
	$hash = hash('whirlpool', $new_password);
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("UPDATE users SET password = ? WHERE login = ?;");
		$stmt->bindValue(1, $hash, PDO::PARAM_STR);
		$stmt->bindValue(2, $login, PDO::PARAM_STR);
		$stmt->execute();
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return (1);
	}
	return (0);
}

function reinit_pass($email)
{
	include ('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT login, email FROM users WHERE email = ?;");
		$stmt->bindValue(1, $email, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetch(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error 1: Could not reach the database";
		return (1);
	}
	if ($result['email'] == "")
	{
		$_SESSION['message'] = "Cette adresse email ne correspond a aucun utilisateur";
		return (1);
	}
	$new = get_new_pass();	
	try
	{
		$stmt2 = $pdo->prepare("UPDATE users SET password= ? WHERE login = ?;");
		$stmt2->bindValue(1, hash('whirlpool', $new), PDO::PARAM_STR);
		$stmt2->bindValue(2, $result['login'], PDO::PARAM_STR);
		$stmt2->execute();
		$stmt2->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error 2: Could not reach the database";
		return (1);
	}
	mail_reinit_pass($email, $new);
	return (0);
}

function get_new_pass()
{
	$ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	$random = "";
	while (strlen($random) < 6)
		$random .= $ch[rand(0, strlen($ch))];
	return ($random);
}

function mail_reinit_pass($email, $new)
{
	$objet = "Camagru - Mot de passe reinitialisation";
	$message = "Bonjour,\nSuite a votre demande, votre mot de passe a ete reinitialise.
		Votre nouveau mot de passe est le suivant: ".$new;
	$headers .= 'From: noreply <noreply@camagru.com>' . "\r\n";
	mail($email, $objet, $message, $headers);
}
?>
