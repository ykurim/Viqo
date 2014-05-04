#ifndef COMMTCP_H
#define COMMTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

#include "mainwindow.h"

class CommTcp : public QObject
{
	Q_OBJECT
public:
	explicit CommTcp(QString domain, int port, QString thread, Ui::MainWindow* mwin);
	void doConnect();

signals:

public slots:
	void connected();
	void disconnected();
	void bytesWritten(qint64 bytes);
	void readyRead();

private:

	MainWindow* mwin;
	QTcpSocket *socket;
	QString domain, thread;
	int port;

};

#endif // COMMTCP_H
