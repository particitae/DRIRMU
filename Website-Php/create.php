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
$db->exec("CREATE TABLE `insectes` ( `id` INTEGER PRIMARY KEY AUTOINCREMENT, `identification` SMALLINT NOT NULL,  `date` DATETIME NOT NULL, `temperature` FLOAT NOT NULL, `humidite` FLOAT NOT NULL, `enregistrement` DATETIME NOT NULL )");
$db->exec("INSERT INTO `insectes` ( `identification`, `date`, `temperature`, `humidite`, `enregistrement`) VALUES ( '001', '2999-01-01 00:00', '7,00', '999', '2999-01-01 00:00')");
?>
