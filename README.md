# Blood-Test-Analyzer
HealthAnalyzer++ – C++ Blood Test Report Analyzer A simple, lightweight C++ console project that analyzes blood test reports from a CSV file and gives medical, nutrition, and fitness recommendations.
📌 Features
✅ Parses blood test markers from a .csv file

✅ Compares values against standard medical reference ranges

✅ Detects low or high values and prints warnings

✅ Provides nutrition tips based on key markers (Vitamin D, Cholesterol, Hemoglobin)

✅ Recommends general exercise routines

✅ Easy to use and extend – clean C++17 code

🛠️ Built With
C++17

STL (<vector>, <map>, <fstream>, <iostream>, <sstream>)

CSV format input for easy integration with lab reports

📂 Sample Input File (data/report.csv)
csv
Copy
Edit
name,value,unit
Hemoglobin,12.5,g/dL
WBC,9200,cells/mcL
Cholesterol,210,mg/dL
Vitamin D,25,ng/mL
💻 How to Compile and Run
bash
Copy
Edit
# Compile with g++ using C++17
g++ -std=c++17 -o health_analyzer main.cpp

# Make sure 'data/report.csv' exists
./health_analyzer
🧪 Sample Output
markdown
Copy
Edit
--- Blood Test Report Analysis ---
Hemoglobin: 12.5 g/dL
  - Low. Consider consulting a doctor.
WBC: 9200 cells/mcL
  - Normal.
Cholesterol: 210 mg/dL
  - High. May need lifestyle or medical changes.
Vitamin D: 25 ng/mL
  - Low. Consider consulting a doctor.

Nutrition Advice:
- Increase sun exposure and eat fatty fish (like salmon).
- Avoid saturated fats. Add oats and fiber-rich foods.
- Eat iron-rich foods (spinach, red meat, lentils).

Exercise Recommendation:
- 30 minutes of walking or light cardio, 5 days a week.
- Include strength training twice a week.
- Stretch daily.
🧠 Future Improvements (PRs Welcome!)
🧾 Add PDF report generation

🌐 Create a web version using Flask or FastAPI

📉 Chart visualizations with blood marker trends

🧬 Add more clinical biomarkers with dynamic reference ranges

