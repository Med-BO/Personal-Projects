<?php
$servername = "localhost";
$username = "root";
$password = "";

//check for delete request
if(count($_GET)!=0){
  try{
    $conn = new PDO("mysql:host=$servername;dbname=students", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $statement = $conn->prepare("DELETE FROM student WHERE id = :id ;");
    $statement->bindParam(":id", $_GET["id"]);
    $statement->execute();
  } catch(PDOException $e){
    echo $e->getMessage();
  }
}
//check for insert request
if(count($_POST)!=0){
try{
  $conn = new PDO("mysql:host=$servername;dbname=students", $username, $password);
  $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
  //echo "connected successfully";
  $statement = $conn->prepare("INSERT INTO student (full_name, class) VALUES(:name, :class);");
  $statement->bindParam(":name", $name);
  $statement->bindParam(":class", $class);
  $name = $_POST["name"];
  $class = $_POST["class"];
  $statement->execute();
} catch(PDOException $e){
  echo $e->getMessage();
}
}
 ?>
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Added !</title>
  </head>
  <body>
    <ul>
    <?php
      $conn = new PDO("mysql:host=$servername;dbname=students", $username, $password);
      $statement = $conn->prepare("SELECT * FROM student;");
      $statement->execute();
      $arr = $statement->fetchAll(PDO::FETCH_ASSOC);
      foreach($arr as $row){ ?>
        <h1>Student n: <?= $row["id"]; ?></h1>
        <li><?= $row["id"]; ?></li>
        <li><?= $row["full_name"]; ?></li>
        <li><?= $row["class"]; ?></li>
        <li><a href="add_student.php?method=get&id=<?= $row["id"]; ?>">Delete</a></li>
      <?php } ?>
    </ul>
    <a href="index.php">Add another student</a>
  </body>
</html>
