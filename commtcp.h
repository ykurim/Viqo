#ifndef COMMTCP_H
#define COMMTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QDateTime>
#include <QProcess>

class MainWindow;

class CommTcp : public QObject
{
	Q_OBJECT
public:
	explicit CommTcp(QString domain, int port, QString thread, MainWindow* mwin);
	void doConnect();
	void close();

signals:

public slots:
	void connected();
	void disconnected();
	void bytesWritten(qint64 bytes);
	void readyRead();
	void readOneRawComment(QByteArray& rawcomm);
	bool isConnected();

private:
	MainWindow* mwin;
	QTcpSocket* socket;
	QString domain, thread;
	int port;
	QDateTime opentime;
	QByteArray lastRawComm;
};

#endif // COMMTCP_H
