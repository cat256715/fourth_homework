#include <bangtal>
using namespace bangtal;
#include <time.h>

SceneID scene1, scene2;
ObjectID cut[11], base[12], start, restart, end;

time_t starttime = time(NULL);
int sum = 0, check[11];
time_t endtime = time(NULL);


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == start) {
		enterScene(scene2);
		for (int i = 0; i < 11; i++) {
			showObject(cut[i]);
		}
	}
	else if (object == restart) {
		hideObject(restart);
		hideObject(end);
		for (int i = 0; i < 11; i++) {
			hideObject(base[i]);
			showObject(cut[i]);
			hideObject(base[11]);
		}
		enterScene(scene1);
	}
	else if (object == end) {
		endGame();
		printf("Time : %lf\n", difftime(endtime, starttime));
	}
	else {
		if (object == cut[6]) {
			hideObject(cut[6]);
			showObject(base[11]);
			check[6] = 1;
		}
		if (object == cut[2] && check[6] == 1) {
			hideObject(cut[2]);
			showObject(base[6]);
			check[2] = 1;
		}
		if (object == cut[7] && check[2] == 1) {
			hideObject(cut[7]);
			showObject(base[2]);
			check[7] = 1;
		}
		if (object == cut[0] && check[7] == 1) {
			hideObject(cut[0]);
			showObject(base[7]);
			check[0] = 1;
		}
		if (object == cut[4] && check[0] == 1) {
			hideObject(cut[4]);
			showObject(base[0]);
			check[4] = 1;
		}
		if (object == cut[8] && check[4] == 1) {
			hideObject(cut[8]);
			showObject(base[4]);
			check[8] = 1;
		}
		if (object == cut[9] && check[8] == 1) {
			hideObject(cut[9]);
			showObject(base[8]);
			check[9] = 1;
		}
		if (object == cut[1] && check[9] == 1) {
			hideObject(cut[1]);
			showObject(base[9]);
			check[1] = 1;
		}
		if (object == cut[3] && check[1] == 1) {
			hideObject(cut[3]);
			showObject(base[1]);
			check[3] = 1;
		}
		if (object == cut[10] && check[3] == 1) {
			hideObject(cut[10]);
			showObject(base[3]);
			check[10] = 1;
		}
		if (object == cut[5] && check[10] == 1) {
			hideObject(cut[5]);
			showObject(base[10]);
			showObject(restart);
			showObject(end);
			for (int i = 0; i < 10000; i++) sum += i;
			printf("Time : %lf\n", difftime(endtime, starttime));
		}
	}
}

int main() {
	setMouseCallback(mouseCallback);
	scene1 = createScene("원본", "Images/원본.jpg");
	scene2 = createScene("배경", "Images/배경.jpg");

	cut[0] = createObject("Images/8.jpg");
	cut[1] = createObject("Images/10.jpg");
	cut[2] = createObject("Images/7.jpg");
	cut[3] = createObject("Images/2.jpg");
	cut[4] = createObject("Images/1.jpg");
	cut[5] = createObject("Images/6.jpg");
	cut[6] = createObject("Images/12.jpg");
	cut[7] = createObject("Images/3.jpg");
	cut[8] = createObject("Images/5.jpg");
	cut[9] = createObject("Images/9.jpg");
	cut[10] = createObject("Images/4.jpg");

	locateObject(cut[0], scene2, 0, 479);
	locateObject(cut[1], scene2, 0, 239);
	locateObject(cut[2], scene2, 0, 0);
	locateObject(cut[3], scene2, 319, 479);
	locateObject(cut[4], scene2, 319, 239);
	locateObject(cut[5], scene2, 319, 0);
	locateObject(cut[6], scene2, 639, 479);
	locateObject(cut[7], scene2, 639, 239);
	locateObject(cut[8], scene2, 639, 0);
	locateObject(cut[9], scene2, 959, 479);
	locateObject(cut[10], scene2, 959, 239);

	base[0] = createObject("Images/1.jpg");
	base[1] = createObject("Images/2.jpg");
	base[2] = createObject("Images/3.jpg");
	base[3] = createObject("Images/4.jpg");
	base[4] = createObject("Images/5.jpg");
	base[5] = createObject("Images/6.jpg");
	base[6] = createObject("Images/7.jpg");
	base[7] = createObject("Images/8.jpg");
	base[8] = createObject("Images/9.jpg");
	base[9] = createObject("Images/10.jpg");
	base[10] = createObject("Images/11.jpg");
	base[11] = createObject("Images/12.jpg");

	locateObject(base[0], scene2, 0, 479);
	locateObject(base[1], scene2, 0, 239);
	locateObject(base[2], scene2, 0, 0);
	locateObject(base[3], scene2, 319, 479);
	locateObject(base[4], scene2, 319, 239);
	locateObject(base[5], scene2, 319, 0);
	locateObject(base[6], scene2, 639, 479);
	locateObject(base[7], scene2, 639, 239);
	locateObject(base[8], scene2, 639, 0);
	locateObject(base[9], scene2, 959, 479);
	locateObject(base[10], scene2, 959, 239);
	locateObject(base[11], scene2, 959, 0);


	for (int i = 0; i < 11; i++) {
		showObject(cut[i]);
	}

	start = createObject("Images/start.jpg");
	locateObject(start, scene1, 590, 70);
	showObject(start);
	restart = createObject("Images/restart.jpg");
	locateObject(restart, scene2, 320, 0);
	end = createObject("Images/end.jpg");
	locateObject(end, scene2, 590, 0);

	startGame(scene1);
}