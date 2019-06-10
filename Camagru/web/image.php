<?php
include('user.php');
include('detailed_img.php');
include('comments.php');
include('create_galerie.php');
$img_path = "../montages/id" . $_GET['id'];
if (login_check() == 1)
{
    $_SESSION['message'] = "Vous devez être connecté pour accéder à cette page";
	header('location:login.php');
}
else if (!file_exists($img_path))
{
    $_SESSION['message'] = "Cette image n'existe pas ! Dommage";
	header('location:galerie.php');
}
else if ($_POST['submit_new_comment'] != null)
{
    postComment($_SESSION['user']['login'], $_POST['new_comment'], $_GET['id']);
}
else if ($_POST['submit_delete_com'] != null)
{
    deleteCom($_POST['id_comment']);
}
$img_src = file_get_contents($img_path);
$id = $_GET['id'];
$aInfo = detailed_img_info($id);
$sNbLikes = nb_likes($id);
$sNbComs = nb_comments($id);
$sIsLiked = is_liked($id, $_SESSION['user']['login']);
?>

<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="theme.css">
        <link rel="stylesheet" type="text/css" href="image.css">
        <title>Camagru - Image</title>
        <link rel="shortcut icon" href="../img/logo_green.png">
         <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.0/jquery.min.js"></script>
        <script src="galerie.js"></script>     
    </head>
    
    <body background="../img/background2.jpg">
        <header class="container">
            <a href="../index.php"><img id="header_logo" src="../img/logo2.png"></a>
            <h1>Camagru</h1>
            <h2><?php echo "Image No: " . $_GET['id']; ?></h2>
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
                <?php if (isset($_SESSION['message'])) {echo $_SESSION['message'];}
                $_SESSION['message'] = "";?>
            </div>
            

            <div id="main">

                <div id="imagePrincipale">
                <?php echo '<img src="' . $img_src . '" / >';?>
                </div>

                <div id="side">
                    <?php echo'<div id="'.$id.'">';?>
                        <?php echo '<button type="button" class="like_button '. $sIsLiked.'" onclick="like_montage('. $id .')">'; ?>
                            like</button>
                        <div id="auteur">Auteur: <?php echo $aInfo['login']?> </div>
                        <div>Nombre de <?php echo '<span class="nb_like">likes: ' . $sNbLikes . '</span>'; ?> </div>
                        <div>Nombre de commentaire(s): <?php echo $sNbComs ?> </div>
                    </div>                
                </div>
            </div>
            <div id="comments_section">
                commentaires :
                <div class="overflow">
                    <?php createCommentsSection($id) ?>
                </div>
                <form action="" method="POST">
                    <input type="text" name="new_comment" />
                    <input type="submit" name="submit_new_comment" value="Poster" />
                </form>
            </div>
        </div>
        <footer>
            Camagru.fr All rights reserved
            <br />Christophe Baldy
        </footer>
    </body>
</html>
