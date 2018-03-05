-- phpMyAdmin SQL Dump
-- version 4.0.9
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 22, 2018 at 12:34 PM
-- Server version: 5.6.14
-- PHP Version: 5.5.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `savedata`
--

-- --------------------------------------------------------

--
-- Table structure for table `tcpdata`
--

CREATE TABLE IF NOT EXISTS `tcpdata` (
  `No` int(150) NOT NULL AUTO_INCREMENT,
  `id` text NOT NULL,
  `mode` text NOT NULL,
  PRIMARY KEY (`No`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=48 ;

--
-- Dumping data for table `tcpdata`
--

INSERT INTO `tcpdata` (`No`, `id`, `mode`) VALUES
(1, '716624841', 'open'),
(2, '716624841', 'close'),
(3, '', 'Intruder'),
(4, '716624841', 'open'),
(5, '', 'Intruder'),
(6, '', 'Intruder'),
(7, '', 'Intruder'),
(8, '716624841', 'open'),
(9, '', 'Intruder'),
(10, '716624841', 'open'),
(11, '', 'Intruder'),
(12, '716624841', 'open'),
(13, '', 'Intruder'),
(14, '', 'Intruder'),
(15, '', 'Intruder'),
(16, '716624841', 'close'),
(17, '716624841', 'open'),
(18, '', 'Intruder'),
(19, '716624841', 'close'),
(20, '716624841', 'open'),
(21, '716624841', 'open'),
(22, '716624841', 'close'),
(23, '716624841', 'open'),
(24, '716624841', 'close'),
(25, '716624841', 'open'),
(26, '716624841', 'close'),
(27, '716624841', 'open'),
(28, '716624841', 'close'),
(29, '716624841', 'open'),
(30, '716624841', 'close'),
(31, '716624841', 'open'),
(32, '716624841', 'close'),
(33, '131190143169', 'Breach'),
(34, '131190143169', 'Breach'),
(35, '716624841', 'open'),
(36, '716624841', 'close'),
(37, '716624841', 'open'),
(38, '131190143169', 'Breach'),
(39, '131190143169', 'Breach'),
(40, '716624841', 'close'),
(41, '716624841', 'open'),
(42, '716624841', 'close'),
(43, '716624841', 'open'),
(44, '716624841', 'close'),
(45, '716624841', 'open'),
(46, '716624841', 'close'),
(47, '131190143169', 'Breach');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
