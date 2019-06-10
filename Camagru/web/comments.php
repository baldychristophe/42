<?php
session_start();

function createCommentsSection($id)
{
	echo '<table id="tableComments">';
	$aComments = getAllComms($id);
	foreach($aComments as $com)
	{
		echo '<tr class="singleComment">';
		echo '<td class="auteur">'.$com['auteur'].'</td>';
		echo '<td class="content">'.$com['content'].'</td>';
		if ($com['auteur'] == $_SESSION['user']['login'])
		{
			echo '<td class="delete"><form method="POST" action="">';
			echo '<input type=hidden name="id_comment" value="'.$com['id_comment'].'" />';
			echo '<input type="submit" name="submit_delete_com" value="supprimer le commentaire" />';
			echo '</form></td>';
		}
		echo '</tr>';
	}
	echo '</table>';
}

function getAllComms($id)
{
	include('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT auteur, content, id_comment FROM comments WHERE id_montage = ?;");
		$stmt->bindValue(1, $id, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return($ex);
	}
	return($result);
}

function deleteCom($id_comment)
{
	include('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("DELETE FROM comments WHERE id_comment = ?;");
		$stmt->bindValue(1, $id_comment, PDO::PARAM_STR);
		$stmt->execute();
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return(1);
	}
	return(0);
}

function postComment($auteur, $content, $id_montage)
{
	include('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("INSERT INTO comments (id_montage, auteur, content) VALUES (?, ?, ?);");
		$stmt->bindValue(1, $id_montage, PDO::PARAM_STR);
		$stmt->bindValue(2, $auteur, PDO::PARAM_STR);
		$stmt->bindValue(3, $content, PDO::PARAM_STR);
		$stmt->execute();
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return(1);
	}
	return(0);
}

?>
