#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <regex>

using namespace std;

class DateUtil {
public:
    // Get today's date in YYYY-MM-DD format
    static string getTodayDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        
        stringstream dateStream;
        dateStream << 1900 + ltm->tm_year << "-"
                   << setfill('0') << setw(2) << 1 + ltm->tm_mon << "-"
                   << setfill('0') << setw(2) << ltm->tm_mday;
        
        return dateStream.str();
    }

    // Validate date format (YYYY-MM-DD)
    static bool isValidDate(const string& dateStr) {
        // Check format using regex
        regex datePattern(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
        if (!regex_match(dateStr, datePattern)) {
            return false;
        }

        // Optional: Check logical validity (like Feb 30)
        int year, month, day;
        char dash1, dash2;
        stringstream ss(dateStr);
        ss >> year >> dash1 >> month >> dash2 >> day;

        if (dash1 != '-' || dash2 != '-') return false;

        // Check days per month
        static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30,
                                           31, 31, 30, 31, 30, 31 };

        if (month < 1 || month > 12) return false;
        int maxDay = daysInMonth[month - 1];

        // Leap year check for February
        if (month == 2 && isLeapYear(year)) {
            maxDay = 29;
        }

        return (day >= 1 && day <= maxDay);
    }

private:
    static bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};
