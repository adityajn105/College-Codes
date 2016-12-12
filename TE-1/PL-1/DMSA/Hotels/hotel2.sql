-- MySQL dump 10.13  Distrib 5.5.49, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: AdityasHotel
-- ------------------------------------------------------
-- Server version	5.5.49-0ubuntu0.12.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `ARCHIVES`
--

DROP TABLE IF EXISTS `ARCHIVES`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ARCHIVES` (
  `hotel_no` int(11) NOT NULL DEFAULT '0',
  `room_no` int(11) NOT NULL,
  `guest_no` int(11) NOT NULL DEFAULT '0',
  `date_from` date NOT NULL,
  `date_to` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ARCHIVES`
--

LOCK TABLES `ARCHIVES` WRITE;
/*!40000 ALTER TABLE `ARCHIVES` DISABLE KEYS */;
INSERT INTO `ARCHIVES` VALUES (1243,1102,4,'2005-05-10','2005-05-20'),(1244,1102,6,'2007-09-20','2007-12-31');
/*!40000 ALTER TABLE `ARCHIVES` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `BOOKINGS`
--

DROP TABLE IF EXISTS `BOOKINGS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `BOOKINGS` (
  `hotel_no` int(11) NOT NULL DEFAULT '0',
  `room_no` int(11) NOT NULL,
  `guest_no` int(11) NOT NULL DEFAULT '0',
  `date_from` date NOT NULL,
  `date_to` date NOT NULL,
  PRIMARY KEY (`hotel_no`,`guest_no`,`date_from`),
  KEY `guest_no` (`guest_no`),
  CONSTRAINT `BOOKINGS_ibfk_1` FOREIGN KEY (`hotel_no`) REFERENCES `HOTEL` (`hotel_no`),
  CONSTRAINT `BOOKINGS_ibfk_2` FOREIGN KEY (`guest_no`) REFERENCES `GUESTS` (`guest_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BOOKINGS`
--

LOCK TABLES `BOOKINGS` WRITE;
/*!40000 ALTER TABLE `BOOKINGS` DISABLE KEYS */;
INSERT INTO `BOOKINGS` VALUES (1243,1105,1,'2008-02-28','2008-06-01'),(1244,1136,7,'2008-10-21','2009-01-30'),(1246,1136,2,'2008-01-06','2008-02-01'),(1246,1110,3,'2009-05-31','2009-06-22'),(1248,1102,5,'2009-09-20','2009-12-31');
/*!40000 ALTER TABLE `BOOKINGS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `GUESTS`
--

DROP TABLE IF EXISTS `GUESTS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `GUESTS` (
  `guest_no` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(40) NOT NULL,
  `address` text,
  PRIMARY KEY (`guest_no`),
  KEY `GUEST_INDEX` (`guest_no`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `GUESTS`
--

LOCK TABLES `GUESTS` WRITE;
/*!40000 ALTER TABLE `GUESTS` DISABLE KEYS */;
INSERT INTO `GUESTS` VALUES (1,'Tyrion','Kings Landing'),(2,'Cersie','Kings Landing'),(3,'Jamie','Kings Landing'),(4,'Daenaerys','Mareen'),(5,'Jon Snow','Winterfell'),(6,'Sansa','Winterfell'),(7,'Arya','Bravoos');
/*!40000 ALTER TABLE `GUESTS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary table structure for view `HAYAT_BOOKING`
--

DROP TABLE IF EXISTS `HAYAT_BOOKING`;
/*!50001 DROP VIEW IF EXISTS `HAYAT_BOOKING`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `HAYAT_BOOKING` (
  `hotel_no` tinyint NOT NULL,
  `room_no` tinyint NOT NULL,
  `guest_no` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `HOTEL`
--

DROP TABLE IF EXISTS `HOTEL`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `HOTEL` (
  `hotel_no` int(11) NOT NULL,
  `name` varchar(40) NOT NULL,
  `city` varchar(20) NOT NULL,
  PRIMARY KEY (`hotel_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `HOTEL`
--

LOCK TABLES `HOTEL` WRITE;
/*!40000 ALTER TABLE `HOTEL` DISABLE KEYS */;
INSERT INTO `HOTEL` VALUES (1243,'Hayat','London'),(1244,'Palms','Goa'),(1246,'Burj Al Arab','London'),(1248,'Lotus','Delhi');
/*!40000 ALTER TABLE `HOTEL` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ROOMS`
--

DROP TABLE IF EXISTS `ROOMS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ROOMS` (
  `room_no` int(11) NOT NULL DEFAULT '0',
  `hotel_no` int(11) NOT NULL DEFAULT '0',
  `type` varchar(30) DEFAULT NULL,
  `price` int(11) DEFAULT NULL,
  PRIMARY KEY (`room_no`,`hotel_no`),
  KEY `hotel_no` (`hotel_no`),
  CONSTRAINT `ROOMS_ibfk_1` FOREIGN KEY (`hotel_no`) REFERENCES `HOTEL` (`hotel_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ROOMS`
--

LOCK TABLES `ROOMS` WRITE;
/*!40000 ALTER TABLE `ROOMS` DISABLE KEYS */;
INSERT INTO `ROOMS` VALUES (1102,1243,'Double Room',32),(1102,1246,'Double Room',32),(1102,1248,'Double Room',63),(1104,1243,'Double Room',32),(1105,1243,'Double Room',32),(1110,1243,'Deluxe AC',63),(1110,1246,'Deluxe AC',63),(1120,1244,'Deluxe AC',32),(1121,1244,'Double Room',32),(1122,1243,'Single Room',NULL),(1136,1244,'Deluxe Room',53),(1136,1246,'Deluxe Room',53),(1140,1244,'Deluxe Room',53),(1156,1243,'AC',42),(1159,1243,'Single Room',53);
/*!40000 ALTER TABLE `ROOMS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary table structure for view `ROOMS_BRIEF`
--

DROP TABLE IF EXISTS `ROOMS_BRIEF`;
/*!50001 DROP VIEW IF EXISTS `ROOMS_BRIEF`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE TABLE `ROOMS_BRIEF` (
  `room_no` tinyint NOT NULL,
  `hotel_no` tinyint NOT NULL,
  `type` tinyint NOT NULL
) ENGINE=MyISAM */;
SET character_set_client = @saved_cs_client;

--
-- Final view structure for view `HAYAT_BOOKING`
--

/*!50001 DROP TABLE IF EXISTS `HAYAT_BOOKING`*/;
/*!50001 DROP VIEW IF EXISTS `HAYAT_BOOKING`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `HAYAT_BOOKING` AS select `BOOKINGS`.`hotel_no` AS `hotel_no`,`BOOKINGS`.`room_no` AS `room_no`,`BOOKINGS`.`guest_no` AS `guest_no` from `BOOKINGS` where (`BOOKINGS`.`hotel_no` = 1243) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `ROOMS_BRIEF`
--

/*!50001 DROP TABLE IF EXISTS `ROOMS_BRIEF`*/;
/*!50001 DROP VIEW IF EXISTS `ROOMS_BRIEF`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `ROOMS_BRIEF` AS select `ROOMS`.`room_no` AS `room_no`,`ROOMS`.`hotel_no` AS `hotel_no`,`ROOMS`.`type` AS `type` from `ROOMS` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-07-19 10:34:57
