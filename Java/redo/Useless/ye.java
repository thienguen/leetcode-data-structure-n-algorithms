
import java.io.IOException;
import java.util.Scanner;

// this assignment suck as much as the next one
public class Time {
    private int hour;
    private int minute;
    private int second;

    // write constructor for class time constructor
    // if user didn't specify a constructor, the default constructor will be called
    public Time() {
        this.hour = 0;
        this.minute = 0;
        this.second = 0;
    }

    public Time(int hour, int minute) {
        if (hour >= 0 && minute >= 0) {
            this.hour = hour;
            if (minute >= 59) {
                // convert minutes to hour and
                // add the rest of minutes to hour
                this.hour += minute / 60;
                this.minute = minute % 60;
            } else {
                this.minute = minute;
            }
        }
    }

    public Time addHours(int hour) {
        if (hour >= 0) {
            this.hour += hour;
        }
        return this;
    }

    // write an add minute method
    public Time addMinute(int minute) {
        if (minute >= 0) {
            this.minute += minute;
            if (this.minute >= 59) {
                this.hour += this.minute / 60;
                this.minute = this.minute % 60;
            }
        }
        return this;
    }

    // write an subtract minute method
    public Time subtractMinute(int minute) {
        if (minute >= 0) {
            this.minute -= minute;
            if (this.minute < 0) {
                this.hour -= 1;
                this.minute = 60 + this.minute;
            }
        }
        return this;
    }

    // write an add second method
    public Time addSecond(int second) {
        if (second >= 0) {
            this.second += second;
            if (this.second >= 59) {
                this.minute += this.second / 60;
                this.second = this.second % 60;
            }
            if (this.minute >= 59) {
                this.hour += this.minute / 60;
                this.minute = this.minute % 60;
            }
        }
        return this;
    }

    public void printTime() { // already wrote this befrore 7 popped up out of nowhere, the f profe?
        if (this.hour >= 12) {
            System.out.println(this.hour - 12 + ":" + this.minute + ":" + this.second + " PM\n" + "Midnight");
            // specify time at noon and midnight
            // if (this.hour > 11 && this.hour <= 12) {
            //     System.out.println("Midnight");
            // }
        } else {
            System.out.println(this.hour + ":" + this.minute + ":" + this.second + " AM\n" + "Noon");
        }
    }

    boolean isPM() {
        if (this.hour >= 12) {
            return true;
        } else {
            return false;
        }
    }

    // write a method to check if the time is valid
    boolean priorTo(Time time) { // prior to Hours
        if (this.hour < time.hour) {
            return true;
        } else if (this.hour == time.hour) { // prior to Minutes
            if (this.minute < time.minute) {
                return true;
            } else if (this.minute == time.minute) { // prior to Seconds
                if (this.second < time.second) {
                    return true;
                } else {
                    return false;
                }
            } else { // not prior to Seconds
                return false;
            }
        } else { // not prior to Minutes
            return false;
        }
    }

    boolean equals(Time time) {
        if (this.hour == time.hour && this.minute == time.minute && this.second == time.second) {
            return true;
        } else {
            return false;
        }
    }

    boolean after(Time time) {
        if (!priorTo(time)) {
            return true;
        } else {
            return false;
        }
    }

    int subtractTime(Time time) { // return the difference between two times in minutes
        this.hour -= time.hour;
        this.minute -= time.minute;
        if (this.minute < 0) {
            this.hour -= 1;
            this.minute += 60;
        }
        return this.hour * 60 + this.minute;
    }

    // print Schedule with the format like this
    // 8:30AM _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 9:00AM _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 9:30AM _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 10:00AM _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 10:30AM _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // 11:00AM _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    public static String Line() {
        String line = "";
        for (int i = 0; i < 20; i++) {
            line += "_ ";
        }
        return line;
    }

    public void printSchedule(Time start, int apptLength, int numberOfAppts) throws IOException {
        for (int i = 0; i < numberOfAppts; i++) {
            // print the time start
            if (start.hour <= 12) {
                if (start.minute > 0) {
                    System.out.println(this.hour + ":" + this.minute + "AM " + Time.Line());
                } else {
                    System.out.println(this.hour + ":" + this.minute + "0AM " + Time.Line());
                }
            } else {
                if (start.minute > 0) {
                    System.out.println(this.hour - 12 + ":" + this.minute + "PM " + Time.Line());
                } else {
                    System.out.println(this.hour - 12 + ":" + this.minute + "0PM " + Time.Line());
                }
            }
            // add the length of the appointment
            start.addMinute(apptLength);
        }
    }

    public void printMilitaryTime() {
        if (this.hour >= 12) {
            System.out.println(this.hour + ":" + this.minute + " PM");
        } else {
            System.out.println(this.hour + ":" + this.minute + " AM");
        }
    }

    void getHour() {
        System.out.println(this.hour);
    }

    void getMinute() {
        System.out.println(this.minute);
    }

    void advanceMinute(int minute) {
        this.minute += minute;
    }


    public static class Date extends Time {
        int day;
        int month;
        int year;

        public Date(int day, int month, int year) {
            this.day = day;
            this.month = month;
            this.year = year;
        }

        public void printDate() {
            System.out.println(this.day + "/" + this.month + "/" + this.year);
        }

        public Date incrementDay(int day) {
            this.day += day;
            return this;
        }

        public void printMonthlyCalendar(int month, int year) {
            int daysInMonth = 0;
            daysInMonth = lastDayOfMonth(month);

            for (int i = 1; i <= daysInMonth; i++) {
                System.out.println(i + "/" + month + "/" + year + " " + Date.Line());
            }
        }


        public int lastDayOfMonth(int month) {
            int day = 0;
            switch (month) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    day = 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    day = 30;
                    break;
                case 2:
                    if (year % 4 == 0) {
                        day = 29;
                    } else {
                        day = 28;
                    }
                    break;
                default:
                    System.out.println("Invalid month");
                    break;
            }
            return day;
        }
    }
    public static void main(String str[]) throws IOException {
        Time start = new Time(8, 30);
        start.printSchedule(start, 30, 6);

        Date date = new Date(1, 1, 2020);

        date.printMonthlyCalendar(1, 2020);
    }
}
