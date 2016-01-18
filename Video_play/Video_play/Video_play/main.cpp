#include "video_play.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Video_play w;
	w.show();
	return a.exec();
}
