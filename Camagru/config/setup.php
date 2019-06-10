<?php
include ('database.php');

try
{
	$pdo = new PDO('mysql:host=127.0.0.1;charset=utf8mb4;port=3307', $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}
catch (PDOException $ex)
{
	echo "Error: Could not Connect to localhost: " . $ex->getMessage();
	die(1);
}

if (file_exists("config/db_camagru.sql") === True)
	$data = file_get_contents("config/db_camagru.sql");
else
{
	echo "Error: Database not found\n";
	die(1);
}

try
{
	$stmt = $pdo->exec($data);
}
catch (PDOException $ex)
{
	echo "Error: Could not create the database: " . $ex->getMessage();
	die(1);
}
echo "Database created successfully\n";
?>
