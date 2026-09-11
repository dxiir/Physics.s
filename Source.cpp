#include<iostream>
#include<cmath>
using namespace std;


struct object {
	string name;
	double x, y, z, ax = 0 ,ay = 0,az = 0,vx = 0,vy = 0,vz = 0;
	double mass;
};

void getacceleration(object& a, object& b);


int main() {
	
	int n;
	cin >> n;
	object* objects = new object[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter pos of object " << i+1 << " x:";
		cin >> objects[i].x;
		cout << "y:";
		cin >> objects[i].y;
		cout << "z:";
		cin >> objects[i].z;
		cout << "Its mass ,ONLY POSITIVE values  (if you enter negative number i will take absolute value) :";
		cin >> objects[i].mass;
		if (objects[i].mass < 0) {
			objects[i].mass *= -1;
		}
		cout << endl;
	}

	while (true) {

		for (int i = 0; i < n; i++) {
			objects[i].ax = 0;
			objects[i].ay = 0;
			objects[i].az = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				getacceleration(objects[i], objects[j]);
			}
		}


		for (int i = 0; i < n; i++) {
			objects[i].vx += 0.001 * objects[i].ax;
			objects[i].vy += 0.001 * objects[i].ay;
			objects[i].vz += 0.001 * objects[i].az;

		}

		for (int i = 0; i < n; i++) {
			objects[i].x += 0.001 * objects[i].vx;
			objects[i].y += 0.001 * objects[i].vy;
			objects[i].z += 0.001 * objects[i].vz;

		}

		for (int i = 0; i < n; i++) {
			cout << "Now tracking pos of " << i + 1 << " x:"<<objects[i].x<<" y:"<< objects[i].y<<" z:"<< objects[i].z<<endl;
		}

	}
	return 0;
}




void getacceleration(object& a, object& b) {
	a.ax = a.ax + (b.x - a.x) * 6.6743 *  b.mass / (((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z))*100000000000 * pow(( (b.x-a.x)* (b.x - a.x) + (b.y - a.y)* (b.y - a.y) + (b.z - a.z) * (b.z - a.z)), 0.5));
	b.ax = b.ax + (a.x - b.x) * 6.6743 * a.mass  / (((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)) * 100000000000 * pow(((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)), 0.5));

	a.ay = a.ay + (b.y - a.y) * 6.6743 *  b.mass / (((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)) * 100000000000 * pow(((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)), 0.5));
	b.ay = b.ay + (a.y - b.y) * 6.6743 * a.mass  / (((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)) * 100000000000 * pow(((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)), 0.5));

	a.az = a.az + (b.z - a.z) * 6.6743 * b.mass / (((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)) * 100000000000 * pow(((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)), 0.5));
	b.az = b.az + (a.z - b.z) * 6.6743 * a.mass  / (((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)) * 100000000000 * pow(((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)), 0.5));




}