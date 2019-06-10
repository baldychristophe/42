<?php
session_start();
include ('../config/database.php');
try
{
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$stmt = $pdo->prepare("SELECT id_montage FROM montages WHERE login = ?");
	$stmt->bindValue(1, $_SESSION['user']['login'], PDO::PARAM_STR);
	$stmt->execute();
	$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
	$stmt->closeCursor();
}
catch (PDOException $ex)
{
	$_SESSION['message'] = "Error: Could not reach the database";
	return (1);
}
$ret = array();
$slice = array_slice($result, -6, 6);
foreach($slice as $elem)
{
	$ret[] = array(
		'id' => $elem['id_montage'],
		'img' => file_get_contents("../montages/id" . $elem['id_montage'])
	);
}
echo json_encode($ret);

?>
