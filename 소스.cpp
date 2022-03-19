#include <bangtal>
using namespace bangtal;
#include <time.h>

SceneID scene1, scene2;
ObjectID cut[11], base[12], start, restart, end;

bool checked[11];

time_t starttime = time(NULL);
int sum = 0;
time_t endtime = time(NULL);

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == start) {
		hideObject(start);
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
	}
	else if (object == end) {
		endGame();
		printf("Time : %lf\n", difftime(endtime, starttime));
	}
	else {
		if (object == cut[6]) {
			hideObject(cut[6]);
			showObject(base[11]);
			if (object == cut[2]) {
				hideObject(cut[2]);
				showObject(base[6]);
				if (object == cut[7]) {
					hideObject(cut[7]);
					showObject(base[2]);
					if (object == cut[0]) {
						hideObject(cut[0]);
						showObject(base[7]);
						if (object == cut[4]) {
							hideObject(cut[4]);
							showObject(base[0]);
							if (object == cut[8]) {
								hideObject(cut[8]);
								showObject(base[4]);
								if (object == cut[9]){
									hideObject(cut[9]);
									showObject(base[8]);
									if (object == cut[1]) {
										hideObject(cut[1]);
										showObject(base[9]);
										if (object == cut[3]){
											hideObject(cut[3]);
											showObject(base[1]);
											if (object == cut[10]) {
												hideObject(cut[10]);
												showObject(base[3]);
												if (object == cut[5]) {
													hideObject(cut[5]);
													showObject(base[10]);
													showObject(restart);
													showObject(end);
													printf("Time : %lf\n", difftime(endtime, starttime));
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	scene1 = createScene("원본","Images\\원본.png");
	scene2 = createScene("배경","Images\\배경.png");

	start = createObject("Images\\start.png");
	locateObject(start, scene1, 590, 70);
	showObject(start);
	restart = createObject("Images\\restart.png");
	locateObject(restart, scene2, 320, 0);
	end = createObject("Images\\end.png");
	locateObject(end, scene2, 590, 0);

	
	cut[0] = createObject("Images\\8.png");
	cut[1] = createObject("Images\\10.png");
	cut[2] = createObject("Images\\7.png");
	cut[3] = createObject("Images\\2.png");
	cut[4] = createObject("Images\\1.png");
	cut[5] = createObject("Images\\6.png");
	cut[6] = createObject("Images\\12.png");
	cut[7] = createObject("Images\\3.png");
	cut[8] = createObject("Images\\5.png");
	cut[9] = createObject("Images\\9.png");
	cut[10] = createObject("Images\\4.png");

	locateObject(cut[0], scene2, 0, 49);
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

	base[0] = createObject("Images\\1.png");
	base[1] = createObject("Images\\2.png");
	base[2] = createObject("Images\\3.png");
	base[3] = createObject("Images\\4.png");
	base[4] = createObject("Images\\5.png");
	base[5] = createObject("Images\\6.png");
	base[6] = createObject("Images\\7.png");
	base[7] = createObject("Images\\8.png");
	base[8] = createObject("Images\\9.png");
	base[9] = createObject("Images\\10.png");
	base[10] = createObject("Images\\11.png");
	base[11] = createObject("Images\\12.png");

	locateObject(base[0], scene2, 0, 49);
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

	for (int i = 0; i < 10000; i++) sum += i;

	for (int i = 0; i < 11; i++) {
		showObject(cut[i]);
	}
	
	startGame(scene1);
}