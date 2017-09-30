#include "azan_calculation.h"
#include <QDebug>

/*Initialize static variable*/
double azan_calc::subuh=0;
double azan_calc::dzuhur=0;
double azan_calc::ashar=0;
double azan_calc::magrib=0;
double azan_calc::isya=0;
double azan_calc::sunRiseTime=0;

unsigned int azan_calc::jam=0;
unsigned int azan_calc::menit=0;


int get_curr_year(){

    time_t dat_time=time(NULL);
    tm data_waktu = *localtime(&dat_time);

    return (1900+data_waktu.tm_year);
}

int get_curr_date(){

  time_t dat_time=time(NULL);
  tm data_waktu = *localtime(&dat_time);

  return data_waktu.tm_mday;

}

int get_curr_month(){
  time_t dat_time=time(NULL);
  tm data_waktu = *localtime(&dat_time);

  return (data_waktu.tm_mon+1);

}

azan_calc::azan_calc(double longitude_i,double latitude_i,int timezone){
    /*This will imported from setting_kota class (static var)*/
    latitude=latitude_i;
      longitude=longitude_i;

        double D = (367 * get_curr_year()) - ((get_curr_year() + (int)((get_curr_month() + 9) / 12)) * 7 / 4) + (((int)(275 *get_curr_month() / 9)) + get_curr_date() - 730531.5);
        double L = 280.461 + 0.9856474 * D;
        L = moreLess360(L);

        double M = 357.528 + (0.9856003) * D;
        M = moreLess360(M);

        double Lambda = L + 1.915 * sin(degToRad(M)) + 0.02 * sin(degToRad(2 * M));
        Lambda = moreLess360(Lambda);

        double Obliquity = 23.439 - 0.0000004 * D;
        double Alpha = radToDeg(atan((cos(degToRad(Obliquity)) * tan(degToRad(Lambda)))));
        Alpha = moreLess360(Alpha);

        Alpha = Alpha - (360 * (int)(Alpha / 360));
        Alpha = Alpha + 90 * (floor(Lambda / 90) - floor(Alpha / 90));

        double ST = 100.46 + 0.985647352 * D;
        double Dec = radToDeg(asin(sin(degToRad(Obliquity)) * sin(degToRad(Lambda))));
        double Durinal_Arc = radToDeg(acos((sin(degToRad(-0.8333)) - sin(degToRad(Dec)) * sin(degToRad(get_lat()))) / (cos(degToRad(Dec)) * cos(degToRad(get_lat())))));

        double Noon = Alpha - ST;
        Noon = moreLess360(Noon);


        double UT_Noon = Noon - get_long();


        ////////////////////////////////////////////
        // Calculating Prayer Times Arcs & Times //
        //////////////////////////////////////////

        // 2) Zuhr Time [Local noon]
        dzuhur = UT_Noon / 15 + timezone;

        // Asr Hanafi
        //double Asr_Alt =radToDeg(atan(2 + tan(degToRad(abs(latitude - Dec)))));

        // Asr Shafii
        double Asr_Alt = radToDeg(atan(1 + tan(degToRad(abs(get_lat() - Dec)))));
        double Asr_Arc = radToDeg(acos((sin(degToRad(90 - Asr_Alt)) - sin(degToRad(Dec)) * sin(degToRad(get_lat()))) / (cos(degToRad(Dec)) * cos(degToRad(get_lat())))));
        Asr_Arc = Asr_Arc / 15;
        // 3) Asr Time
        ashar = get_dzuhur() + Asr_Arc;

        // 1) Shorouq Time
        sunRiseTime = get_dzuhur() - (Durinal_Arc / 15);

        // 4) Maghrib Time
        magrib = get_dzuhur() + (Durinal_Arc / 15);


        double Esha_Arc = radToDeg(acos((sin(degToRad(ISHA_TWILIGHT_SEA)) - sin(degToRad(Dec)) * sin(degToRad(get_lat()))) / (cos(degToRad(Dec)) * cos(degToRad(get_lat())))));
        // 5) Isha Time
        isya =( get_dzuhur() + (Esha_Arc / 15))+2.3;

        // 0) Fajr Time
        double Fajr_Arc = radToDeg(acos((sin(degToRad(FAJR_TWILIGHT_SEA)) - sin(degToRad(Dec)) * sin(degToRad(get_lat()))) / (cos(degToRad(Dec)) * cos(degToRad(get_lat())))));
        subuh = (get_dzuhur() - (Fajr_Arc / 15))-2;

        return;

}

void convert_to_hour(double result,int &hours,int &minutes){

    hours = floor(max_24(result));
    minutes = ((result - hours) * 60);
    azan_calc::set_waktu(hours,minutes);
}

int max_24(double value){
  while(value > 24 || value < 0)
  {
      if(value > 24)
          value -= 24;

      else if (value <0)
          value += 24;

  }

  return value;

}

double azan_calc::moreLess360(double value){
  while(value > 360 || value < 0)
  {
      if(value > 360)
          value -= 360;

      else if (value <0)
          value += 360;
  }

    return value;

}
double azan_calc::radToDeg(double radian){

    return (radian * (180/3.1415926));
}

double azan_calc::degToRad(double degree){
    return ((3.1415926 / 180) * degree);

}

double azan_calc::get_lat(){
    return this->latitude;
}

double azan_calc::get_long(){

    return this->longitude;
}

double azan_calc::get_subuh(){
    return subuh;

}
double azan_calc::get_dzuhur(){
    return dzuhur;
}
double azan_calc::get_ashar(){
    return ashar;

}
double azan_calc::get_magrib(){
    return magrib;
}
double azan_calc::get_isya(){
    return isya;
}


void azan_calc::set_waktu(int _jam, int _minute){

    azan_calc::jam=_jam;
    azan_calc::menit=_minute;

}


double azan_calc::be_positive(double result){
    if(result<0){
        return result*(-1);
    }
    else
        return result;
}

//int azan_calc::get_jam(){
//    return jam;
//}

//int azan_calc::get_menit(){
//    return menit;
//}
