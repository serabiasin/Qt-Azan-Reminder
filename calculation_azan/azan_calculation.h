#ifndef AZAN_CALCLUATION_H
#define AZAN_CALCLUATION_H

/*Bismillahirahamannirahim...*/

/* INSPIRED BY https://ideone.com/ndCpBe */

#include <math.h>
#include <ctime>
#include "setting_azan/setting_kota.h"

/* _NOTE_ : THIS FOR INDONESIA COUNTRY and arround it*/
#define FAJR_TWILIGHT_SEA 17.5 //Untuk daerah malaysia dan sekitarnya(Termasuk Indonesia)
#define ISHA_TWILIGHT_SEA 18 //Untuk daerah malaysia dan sekitarnya(Termasuk Indonesia)

int get_curr_year();
int get_curr_date();
int get_curr_month();
void convert_to_hour(double result,int &hours,int &minutes); //mengubah hasil kalkulasi ke jam
int max_24(double value);

class azan_calc {

private:
double latitude; // diambil menggunakan sqlite
double longitude; //sama
static double subuh; //masih dalam bentuk koma
static double dzuhur;
static double ashar;
static double magrib;
static double isya;
static double sunRiseTime;

public:
  azan_calc (double longitude_i,double latitude_i,int timezone);
  double moreLess360(double value);
  double radToDeg(double radian);
  double degToRad(double degree);
  double get_lat();
  double get_long();

  static double get_subuh();
  static double get_dzuhur();
  static double get_ashar();
  static double get_magrib();
  static double get_isya();



};


#endif
