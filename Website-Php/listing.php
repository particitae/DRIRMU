<?php
/**
 *  * Simple example of extending the SQLite3 class and changing the
 *  __construct
 *   * parameters, then using the open method to initialize the DB.
 *    */
class MyDB extends SQLite3
    {
    function __construct()
    {
        $this->open('mysqlitedb.db');
    }
}
$db = new MyDB();
$result = $db->query('SELECT * FROM insectes');
while ($row = $result->fetchArray(SQLITE3_ASSOC)) {
   echo $row['id']."|".$row['identification'] . "|". $row['date'] . "|" . $row['temperature']. "|" . $row['humidite'] . "|" . $row['enregistrement'] . "</br>"; 
}
?>
