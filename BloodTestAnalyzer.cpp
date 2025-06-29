// HealthAnalyzer++ - Full C++ Blood Test Analysis Project
// Compile with: g++ -std=c++17 -o health_analyzer main.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

struct Marker {
    std::string name;
    double value;
    std::string unit;
};

std::vector<Marker> parseCSV(const std::string& filepath) {
    std::ifstream file(filepath);
    std::vector<Marker> markers;
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, valueStr, unit;
        std::getline(ss, name, ',');
        std::getline(ss, valueStr, ',');
        std::getline(ss, unit);

        Marker m;
        m.name = name;
        m.value = std::stod(valueStr);
        m.unit = unit;
        markers.push_back(m);
    }
    return markers;
}

int main() {
    const std::string filepath = "data/report.csv";
    std::ifstream file(filepath);
    std::string line;

    std::map<std::string, std::pair<double, double>> refRanges = {
        {"Hemoglobin", {13.0, 17.0}},
        {"WBC", {4000, 10000}},
        {"Cholesterol", {0, 200}},
        {"Vitamin D", {30, 100}}
    };

    std::vector<Marker> markers = parseCSV(filepath);

    std::cout << "--- Blood Test Report Analysis ---\n";
    for (const auto& m : markers) {
        std::cout << m.name << ": " << m.value << " " << m.unit << "\n";
        if (refRanges.count(m.name)) {
            auto range = refRanges[m.name];
            double low = range.first;
            double high = range.second;

            if (m.value < low)
                std::cout << "  - Low. Consider consulting a doctor.\n";
            else if (m.value > high)
                std::cout << "  - High. May need lifestyle or medical changes.\n";
            else
                std::cout << "  - Normal.\n";
        } else {
            std::cout << "  - No reference range available.\n";
        }
    }

    std::cout << "\nNutrition Advice:\n";
    for (const auto& m : markers) {
        if (m.name == "Vitamin D" && m.value < 30)
            std::cout << "- Increase sun exposure and eat fatty fish (like salmon).\n";
        if (m.name == "Cholesterol" && m.value > 200)
            std::cout << "- Avoid saturated fats. Add oats and fiber-rich foods.\n";
        if (m.name == "Hemoglobin" && m.value < 13)
            std::cout << "- Eat iron-rich foods (spinach, red meat, lentils).\n";
    }

    std::cout << "\nExercise Recommendation:\n";
    std::cout << "- 30 minutes of walking or light cardio, 5 days a week.\n";
    std::cout << "- Include strength training twice a week.\n";
    std::cout << "- Stretch daily.\n";

    return 0;
}
