<?php
session_start();

function create_galerie()
{
	$aId = get_all_montage_id();
	$iIndex = 0;
	echo '<table id="galerie_table"><tr>';
	foreach($aId as $elem)
	{
		if (file_exists("../montages/id" . $elem['id_montage']))
		{
			if ($iIndex % 3 == 0 && $iIndex != 0)
				echo "</tr><tr>";
			echo insert_elem($elem);
			$iIndex++;
		}
	}
	echo '</tr></table>';
}

function insert_elem($elem)
{
	$id = $elem['id_montage'];
	$img_path = "../montages/id" . $id;
	$all_likes = get_montage_likes($id);
	$nb_likes = count($all_likes);
	$is_liked = is_liked_by_user($all_likes);
	return ('<td class="single_elem" id="' . $id . '">
		<a href="image.php?id=' . $elem['id_montage'] . '">
		<img src="' . file_get_contents($img_path) . '" id="single_img" />
		</a>
		<button type="button" class="like_button '. $is_liked .
		'" onclick="like_montage(' . $id . ')">
		like</button>
		<span class="nb_like">likes: ' . $nb_likes . '</span>
		<span class="nb_comment">commentaires: </span>
		</td>');
}

function get_montage_likes($id)
{
	include('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT auteur FROM likes WHERE id_montage = ?;");
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

	return ($result);
}

function is_liked_by_user($all)
{
	foreach($all as $elem)
	{
		if (in_array($_SESSION['user']['login'], $elem))
			return ("clicked");
	}
	return ("");
}

function get_all_montage_id()
{
	include('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT id_montage FROM montages ORDER BY id_montage DESC;");
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
?>
