-- MySQL dump 10.13  Distrib 5.5.49, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: AdityaHotels
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
INSERT INTO `BOOKINGS` VALUES (1243,1105,1,'2016-05-12','2016-08-12'),(1243,1102,4,'2005-05-10','2005-05-20'),(1244,1102,6,'2007-09-20','2007-12-31'),(1244,1136,7,'2008-10-21','2009-01-30'),(1246,1136,2,'2008-01-06','2008-02-01'),(1246,1110,3,'2009-05-31','2009-06-22'),(1248,1102,5,'2009-09-20','2009-12-31');
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
  PRIMARY KEY (`guest_no`)
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
INSERT INTO `ROOMS` VALUES (1102,1243,'Double Room',32),(1102,1246,'Double Room',32),(1102,1248,'Double Room',63),(1104,1243,'Double Room',32),(1105,1243,'Double Room',32),(1110,1243,'Deluxe AC',63),(1110,1246,'Deluxe AC',63),(1120,1244,'Deluxe AC',32),(1121,1244,'Double Room',32),(1136,1244,'Deluxe Room',53),(1136,1246,'Deluxe Room',53),(1140,1244,'Deluxe Room',53),(1156,1243,'AC',42),(1159,1243,'Single Room',53);
/*!40000 ALTER TABLE `ROOMS` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-07-22 10:37:35
