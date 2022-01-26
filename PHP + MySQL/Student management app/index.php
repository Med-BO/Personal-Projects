<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Student management</title>
    <link rel="stylesheet" href="CSS/style.css">
  </head>
  <body>
    <div class="main-content">
      <h1>Add a student</h1>
      <form action="add_student.php" method="post">
        <label>Full name</label>
        <input type="text" name="name"><br>
        <label>Class</label>
        <input type="text" name="class"><br>
        <input type="submit" name="btn" id="btn" value="ADD" size="20">
      </form>
    </div>
    <p id="help">?</p>
    <div class="help-content">
      <p>Provide the full<br>  name and the <br> class of
        the<br>  Student you <br> want to add<br>  to the database</p>
    </div>
  </body>
</html>
