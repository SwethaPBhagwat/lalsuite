<html>
<head>
<?php
//This is the filename we want to parse
//It will be called by fopen later
$uFile="H0ElogFlags.ilwd";
$uTitle="Hanford, WA Elog DQ Flags";

require './scripts/parser.php';
require './scripts/gentable.php';

$arItems=runparser($uFile);
//now $arItems contains the records from $uFile and
//$tbhead contains an array for the table headings
require './scripts/styletitle.php';
?>
</head>
<body>
<?php
//Table displaying logos and $uTitle
require './scripts/header.php';

//Generates table using $tbhead for headers and $arItems for records
make_table($arItems,$tbhead,FALSE);

require './scripts/footer.php';
?>
</body>
</html>
