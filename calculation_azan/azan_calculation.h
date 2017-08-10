#ifndef AZAN_CALCLUATION_H
#define AZAN_CALCLUATION_H

/*Bismillahirahamannirahim...*/

/* INSPIRED BY https://ideone.com/ndCpBe */

#include <math.h>
#include <ctime>
/* _NOTE_ : THIS FOR INDONESIA COUNTRY */
#define FAJR_TWILIGHT_SEA 19.5 //Untuk daerah malaysia dan sekitarnya(Termasuk Indonesia)
#define ISHA_TWILIGHT_SEA 17.5 //Untuk daerah malaysia dan sekitarnya(Termasuk Indonesia)

int get_curr_year();
int get_curr_date();
int get_curr_month();
void convert_to_hour(double result,int &hours,int &minutes); //mengubah hasil kalkulasi ke jam
int max_24(double value);

class azan_calc {

private:
double latitude; // diambil menggunakan sqlite
double longitude; //sama
double subuh; //masih dalam bentuk koma
double dzuhur;
double ashar;
double magrib;
double isya;
double sunRiseTime;

public:
  azan_calc (double longitude_i,double latitude_i,int timezone);
  double moreLess360(double value);
  double radToDeg(double radian);
  double degToRad(double degree);
  double get_lat();
  double get_long();
  double get_subuh();
  double get_dzuhur();
  double get_ashar();
  double get_magrib();
  double get_isya();

};


#endif
