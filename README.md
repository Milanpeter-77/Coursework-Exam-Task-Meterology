# High School IT Final Exam Task: **Meteorological Report - Weather Data Processing**

This task was part of my final exams back at high school. The description were in Hungarian, and I added comments to my code in Hungarian as well. This summary helps to understand it. Mind you that this code is a result of a very specific task, required for an exam, and it is not meant to be educational.

## Task Overview:
I was given a file named `tavirathu13.txt` containing weather telegrams from different cities for the 13th day of a given month.  
Each line of the file represents a single telegram and contains **four pieces of data**:
- City code (2 characters, e.g., `BP`, `PA`)
- Timestamp (hour and minute combined into a 4-digit number, e.g., `0315` for 03:15 AM)
- Wind data (wind direction in degrees + wind speed in knots, e.g., `32007` is 320° direction, 7 knots speed; `VRB01` means variable direction at 1 knot)
- Temperature in Celsius.

Example line from the file:
```
BP 0300 32007 21
```

**The tasks I had to solve:**
1. **Read** the data from the file into memory, organize the data into a list of measurements.
2. **Ask the user** for a city code and **print the last measurement time** for that city.
3. **Find** and print **the city and time for the lowest and highest temperatures** of the day.
4. **Detect** and list **all cities and times where there was a calm (no wind)**, identified by a `00000` wind code.
5. For each city:
   - Calculate the **daily average temperature** based only on measurements made at 1:00, 7:00, 13:00, and 19:00 hours.
     - If **any of these times is missing**, output `NA` for that city's average temperature.
   - Calculate the **daily temperature fluctuation** (difference between highest and lowest temperature).
6. **Create a separate text file for each city**, named `<citycode>.txt`, containing:
   - The city code in the first line.
   - The list of all measurement times and a graphical representation of the wind strength using `#` characters (one `#` per knot).

---

# How My Code Solves This:

- **Data Structures:**
  - `adat_elem`: stores one weather report (city, time, wind, temperature).
  - `varos_adat`: stores summary information about a city (min/max temperature, sums, counts).
- **Functions:**
  - `feladat1()`: Reads the file, stores all measurements, and identifies all cities.
  - `feladat2()`: Asks for a city code and outputs the last measurement time for that city.
  - `feladat3()`: Finds the cities/times of the minimum and maximum temperatures.
  - `feladat4()`: Lists all occurrences of calm winds, or prints a message if there were none.
  - `feladat5()`: Calculates and prints the daily average temperature (if possible) and the daily temperature fluctuation for each city.
  - `feladat6()`: Creates one text file per city, listing times and corresponding numbers of `#` for the wind speed.
- **Main Program:**
  - Runs all the above tasks sequentially.

---

# Additional Notes:
- **Input:** No validation is required because the input file is assumed to be correctly formatted.
- **Output:** Messages and results are displayed on the console exactly as the task specifies.
- **File Creation:** Each city's separate file visually shows the wind strength using `#` symbols.
