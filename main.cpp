#include <iostream>
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

using namespace std;

int main()
{
    char answer;
    string stranswer;
    double numanswer;
    
    cout << "Version: 1.8" << endl;
    cout << "Press 'a' to go to basic calculator, press 'b' to find the area of a circle, press 'c' to find the hight of an object, press 'd' to find the circumfrance of a circle," << endl; 
    cout << "press 'e' to find V1, press 'f' to find the volume of a cylinder, press 'g' to find the surface area of a sphere, or press 'h' to find the volume of a sphere: ";
    cin >> answer;
    
    if (answer == 'a') {
        double num1, num2;
        char op;
        cout << "Enter 1st number ";
        cin >> num1;
        cout << "Enter operator (+, -, *, /) ";
        cin >> op;
        cout << "Enter 2nd number ";
        cin >> num2;
        
        if (op == '+'){
            double result = num1 + num2;
            cout << result;
        } else if (op == '-'){
            double result = num1 - num2;
            cout << result;
        } else if (op == '*'){
            double result = num1 * num2;
            cout << result;
        } else if (op == '/'){
            double result =  num1 / num2;
            cout << result;
        } else {
            cout << "Invalid operator.";
        }
    
    } else if (answer == 'b') {
        double radius;
        
        cout << "what's the radius? ";
        cin >> radius;
        cout << radius * radius * PI;
        
    } else if (answer == 'c') {
        double distance;
        double degree;
        
        cout << "How far away were you? ";
        cin >> distance;
        cout << "What angle was it at? ";
        cin >> degree;
        
        if (degree == 45) {
            cout << distance;
            
        } else {
            double oneresult = distance * tan(degree);
            double tworesult = oneresult - oneresult - oneresult - oneresult;
            double result = oneresult + tworesult;
            cout << result;
            
        }
        
    } else if (answer == 'd') {
        double radius;
        
        cout << "what's the radius? ";
        cin >> radius;
        cout << 2 * PI * radius;
        
    } else if (answer == 'q') {
        cout << "Press 'e' for easy difficulty, press 'm' for medium difficulty, press 'h' for hard difficulty, or press 'x' for extreme difficulty: ";
        cin >> answer;
        
        if (answer == 'e') {
            cout << "What's 6 + 8?" << endl;
            cin >> answer;
            
            if (numanswer == 14) {
                cout << "correct! Whats 3 + 12?" << endl;
                cin >> answer;
                
                if (numanswer == 15) {
                    cout << "correct! What's 32 + 18?" << endl;
                    cin >> answer;
                    
                    if (numanswer == 50) {
                        cout << "correct! What's 40 - 10?" << endl;
                        cin >> answer;
                        
                        if (numanswer == 30) {
                            cout << "correct!";
                            
                        } else {
                            cout << "Incorrect";
                        }
                        
                        
                    } else {
                        cout << "Incorrect";
                        
                    }
                    
                } else {
                    cout << "Incorrect";
                }
                
            } else {
                cout << "Incorrect";
            }
            
        } else if (answer == 'm') {
            cout << "What's 34 + 86?" << endl;
            cin >> answer;
            
            if (numanswer == 120) {
                cout << "correct! Whats 3236 - 1209?" << endl;
                cin >> answer;
                
                if (numanswer == 2027) {
                    cout << "correct! What's 32 * 18?" << endl;
                    cin >> answer;
                    
                    if (numanswer == 576) {
                        cout << "correct! What's 40 / 10?" << endl;
                        cin >> answer;
                        
                        if (numanswer == 4) {
                            cout << "correct!";
                            
                        } else {
                            cout << "Incorrect";
                        }
                        
                        
                    } else {
                        cout << "Incorrect";
                        
                    }
                    
                } else {
                    cout << "Incorrect";
                }
                
            } else {
                cout << "Incorrect";
            }
            
        } else if (answer == 'h') {
           cout << "What's 68 * 88?" << endl;
            cin >> answer;
            
            if (numanswer == 5984) {
                cout << "correct! Whats 5556.5 / 883.45 rounded to the nearest tenth?" << endl;
                cin >> answer;
                
                if (numanswer == 6.2) {
                    cout << "correct! What's 32.18 / 18.32 rounded to the nearest hundreth?" << endl;
                    cin >> answer;
                    
                    if (numanswer == 1.75) {
                        cout << "correct!";
                        
                    } else {
                        cout << "Incorrect";
                        
                    }
                    
                } else {
                    cout << "Incorrect";
                }
                
            } else {
                cout << "Incorrect";
            } 
            
        } else if (answer == 'x') {
            cout << "What's 634 / 2836 rounded to the nearest thousanth?" << endl;
            cin >> answer;
            
            if (numanswer == 0.223) {
                cout << "correct!";
                
            } else {
                cout << "Incorrect";
            }
            
        } else {
            cout << "Select an option next time.";
        }
    } else if (answer == 'e') {
        double rl;
        double fve;
        double acceleration;
        
        cout << "How long's the runway in feet?" << endl;
        cin >> rl;
        cout << "Do you know the final velocity?" << endl;
        cin >> stranswer;
        
        if (stranswer == "yes") {
            cout << "Good, is it mph, kts, or kph?" << endl;
            cin >> stranswer;
            if (stranswer == "mph") {
                cout << "Ok, what is it?" << endl;
                cin >> fve;
                cout << "What's the acceleration in ft/s?" << endl;
                cin >> acceleration;
                
                double fvone = fve * 5280;
                double fv = fvone / 1200;
                double dtv = fv / acceleration;
                double dv = rl - dtv;
                double sv = sqrt(dv);
                double stv = sqrt(dtv);
                double s = sv - stv;
                double r = rl - s;
                double decceleration = 0 - acceleration;
                double t = s - decceleration;
                double x = t - r;
                double vone = rl - x;
                
                cout << "V1 = " << vone << "";
                
            } else if (stranswer == "kts") {
                cout << "Ok, what is it?" << endl;
                cin >> fve;
                cout << "What's the acceleration in ft/s?" << endl;
                cin >> acceleration;
                
                double fvone = fve * 1.151;
                double fvtwo = fvone * 5280;
                double fv = fvtwo / 1200;
                double dtv = fv / acceleration;
                double dv = rl - dtv;
                double sv = sqrt(dv);
                double stv = sqrt(dtv);
                double s = sv - stv;
                double r = rl - s;
                double decceleration = 0 - acceleration;
                double t = s - decceleration;
                double x = t - r;
                double vone = rl - x;
                
                cout << "V1 = " << vone << "";
                
            } else if (stranswer == "kph") {
                cout << "Ok, what is it?" << endl;
                cin >> fve;
                cout << "What's the acceleration in ft/s?" << endl;
                cin >> acceleration;
                
                double fvone = fve / 1.6;
                double fvtwo = fvone * 5280;
                double fv = fvtwo / 1200;
                double dtv = fv / acceleration;
                double dv = rl - dtv;
                double sv = sqrt(dv);
                double stv = sqrt(dtv);
                double s = sv - stv;
                double r = rl - s;
                double decceleration = 0 - acceleration;
                double t = s - decceleration;
                double x = t - r;
                double vone = rl - x;
                
                cout << "V1 = " << vone << "";
                
            } else {
                cout << "Select an option next time.";
            }
            
    } else {
    double acceleration;
    double ive;
    double timee;
    double length;
    
    cout << "What's the acceleration in ft/s?" << endl;
    cin >> acceleration;
    cout << "Do you know the time?" << endl;
    cin >> stranswer;
    
        if (stranswer == "yes") {
            cout << "what is it?" << endl;
            cin >> timee;
            
            double fve = ive + acceleration * timee;
            
            cout << "Do you want to know the final velocity?" << endl;
            cin >> stranswer;
            
            if (stranswer == "yes") {
                cout << "Ok, the final velocity is: " << fve << ". Is it in kph, kts, or mph? ";
                cin >> stranswer;
                    if (stranswer == "mph") {
                        
                        double fvone = fve * 5280;
                        double fv = fvone / 1200;
                        double dtv = fv / acceleration;
                        double dv = rl - dtv;
                        double sv = sqrt(dv);
                        double stv = sqrt(dtv);
                        double s = sv - stv;
                        double r = rl - s;
                        double decceleration = 0 - acceleration;
                        double t = s - decceleration;
                        double x = t - r;
                        double vone = rl - x;
                        
                        cout << "V1 = " << vone << "";
                        
                    } else if (stranswer == "kts") {
                        
                        double fvone = fve * 1.151;
                        double fvtwo = fvone * 5280;
                        double fv = fvtwo / 1200;
                        double dtv = fv / acceleration;
                        double dv = rl - dtv;
                        double sv = sqrt(dv);
                        double stv = sqrt(dtv);
                        double s = sv - stv;
                        double r = rl - s;
                        double decceleration = 0 - acceleration;
                        double t = s - decceleration;
                        double x = t - r;
                        double vone = rl - x;
                        
                        cout << "V1 = " << vone << "";
                        
                    } else if (stranswer == "kph") {
                        
                        double fvone = fve / 1.6;
                        double fvtwo = fvone * 5280;
                        double fv = fvtwo / 1200;
                        double dtv = fv / acceleration;
                        double dv = rl - dtv;
                        double sv = sqrt(dv);
                        double stv = sqrt(dtv);
                        double s = sv - stv;
                        double r = rl - s;
                        double decceleration = 0 - acceleration;
                        double t = s - decceleration;
                        double x = t - r;
                        double vone = rl - x;
                        
                        cout << "V1 = " << vone << "";
                        
                    }           
                    
                    } else {
                                cout << "Ok. Is it in kph, kts, or mph? ";
        cin >> stranswer;
            if (stranswer == "mph") {
                
                double fvone = fve * 5280;
                double fv = fvone / 1200;
                double dtv = fv / acceleration;
                double dv = rl - dtv;
                double sv = sqrt(dv);
                double stv = sqrt(dtv);
                double s = sv - stv;
                double r = rl - s;
                double decceleration = 0 - acceleration;
                double t = s - decceleration;
                double x = t - r;
                double vone = rl - x;
                
                cout << "V1 = " << vone << "";
                
            } else if (stranswer == "kts") {
                
                double fvone = fve * 1.151;
                double fvtwo = fvone * 5280;
                double fv = fvtwo / 1200;
                double dtv = fv / acceleration;
                double dv = rl - dtv;
                double sv = sqrt(dv);
                double stv = sqrt(dtv);
                double s = sv - stv;
                double r = rl - s;
                double decceleration = 0 - acceleration;
                double t = s - decceleration;
                double x = t - r;
                double vone = rl - x;
                
                cout << "V1 = " << vone << "";
                
            } else if (stranswer == "kph") {
                
                double fvone = fve / 1.6;
                double fvtwo = fvone * 5280;
                double fv = fvtwo / 1200;
                double dtv = fv / acceleration;
                double dv = rl - dtv;
                double sv = sqrt(dv);
                double stv = sqrt(dtv);
                double s = sv - stv;
                double r = rl - s;
                double decceleration = 0 - acceleration;
                double t = s - decceleration;
                double x = t - r;
                double vone = rl - x;
                
                cout << "V1 = " << vone << "";
            }
                    }
        } else {
                        double fve = sqrt(ive * ive + 2 * (acceleration * rl));
            
            cout << "Do you want to know the final velocity?" << endl;
            cin >> stranswer;
            
            if (stranswer == "yes") {
                cout << "Ok, the final velocity is: " << fve << endl;
                cout << ". Is it in kph, kts, or mph? " << endl;
                cin >> stranswer;
                    if (stranswer == "mph") {
                        
                        double fvone = fve * 5280;
                        double fv = fvone / 1200;
                        double dtv = fv / acceleration;
                        double dv = rl - dtv;
                        double sv = sqrt(dv);
                        double stv = sqrt(dtv);
                        double s = sv - stv;
                        double r = rl - s;
                        double decceleration = 0 - acceleration;
                        double t = s - decceleration;
                        double x = t - r;
                        double vone = rl - x;
                        
                        cout << "V1 = " << vone << "";
                        
                    } else if (stranswer == "kts") {
                        
                        double fvone = fve * 1.151;
                        double fvtwo = fvone * 5280;
                        double fv = fvtwo / 1200;
                        double dtv = fv / acceleration;
                        double dv = rl - dtv;
                        double sv = sqrt(dv);
                        double stv = sqrt(dtv);
                        double s = sv - stv;
                        double r = rl - s;
                        double decceleration = 0 - acceleration;
                        double t = s - decceleration;
                        double x = t - r;
                        double vone = rl - x;
                        
                        cout << "V1 = " << vone << "";
                        
                    } else if (stranswer == "kph") {
                        
                        double fvone = fve / 1.6;
                        double fvtwo = fvone * 5280;
                        double fv = fvtwo / 1200;
                        double dtv = fv / acceleration;
                        double dv = rl - dtv;
                        double sv = sqrt(dv);
                        double stv = sqrt(dtv);
                        double s = sv - stv;
                        double r = rl - s;
                        double decceleration = 0 - acceleration;
                        double t = s - decceleration;
                        double x = t - r;
                        double vone = rl - x;
                        
                        cout << "V1 = " << vone << "";
                        
                    }           
                    
                    } else {
                                cout << "Ok. Is it in kph, kts, or mph? ";
        cin >> stranswer;
            if (stranswer == "mph") {
                
                double fvone = fve * 5280;
                double fv = fvone / 1200;
                double dtv = fv / acceleration;
                double dv = rl - dtv;
                double sv = sqrt(dv);
                double stv = sqrt(dtv);
                double s = sv - stv;
                double r = rl - s;
                double decceleration = 0 - acceleration;
                double t = s - decceleration;
                double x = t - r;
                double vone = rl - x;
                
                cout << "V1 = " << vone << "";
                
            } else if (stranswer == "kts") {
                
                double fvone = fve * 1.151;
                double fvtwo = fvone * 5280;
                double fv = fvtwo / 1200;
                double dtv = fv / acceleration;
                double dv = rl - dtv;
                double sv = sqrt(dv);
                double stv = sqrt(dtv);
                double s = sv - stv;
                double r = rl - s;
                double decceleration = 0 - acceleration;
                double t = s - decceleration;
                double x = t - r;
                double vone = rl - x;
                
                cout << "V1 = " << vone << "";
                
            } else if (stranswer == "kph") {
                
                double fvone = fve / 1.6;
                double fvtwo = fvone * 5280;
                double fv = fvtwo / 1200;
                double dtv = fv / acceleration;
                double dv = rl - dtv;
                double sv = sqrt(dv);
                double stv = sqrt(dtv);
                double s = sv - stv;
                double r = rl - s;
                double decceleration = 0 - acceleration;
                double t = s - decceleration;
                double x = t - r;
                double vone = rl - x;
                
                cout << "V1 = " << vone << "";
        }
    
    }
    
    }
    
    }
    
    } else if (answer == 'f') {
        double radius;
        double height;
        
        cout << "What's the radius?" << endl;
        cin >> radius;
        cout << "What's the height?" << endl;
        cin >> height;
        
        double volume = PI * (radius * radius) * height;
        
        cout << "The volume is: " << volume;
        
    } else if (answer == 'g') {
        double radius;
        
        cout << "What's the radius?" << endl;
        cin >> radius;
        
        double area = 4 * PI * (radius * radius);
        
        cout << "The surface area is: " << area;
        
    } else if (answer == 'h') {
        double radius;
        
        cout << "What's the radius?" << endl;
        cin >> radius;
        
        double volume = (4 / 3) * PI * (radius * radius);
        
        cout << "The volume is: " << volume;
        
    } else {
        cout << "select an option next time";
    }
    
    return 0;
}
