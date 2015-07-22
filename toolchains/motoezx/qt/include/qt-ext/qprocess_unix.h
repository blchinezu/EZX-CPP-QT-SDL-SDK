#ifndef QPROCESS_UNIX_H
#define QPROCESS_UNIX_H

#include "qprocess.h"
#include <qqueue.h>
#include <qsocketnotifier.h>

// ### FOR Qt 2.3 compat
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>


/***********************************************************************
 *
 * QProc
 *
 **********************************************************************/
/*
  The class QProcess does not necessarily map exactly to the running
  child processes: if the process is finished, the QProcess class may still be
  there; furthermore a user can use QProcess to start more than one process.

  The helper-class QProc has the semantics that one instance of this class maps
  directly to a running child process.
*/
class QProc;
class QProcessManager;
class QProcessPrivate
{
public:
    QProcessPrivate();
    ~QProcessPrivate();

    void closeOpenSocketsForChild();
    void newProc( pid_t pid, QProcess *process );

    QByteArray bufStdout;
    QByteArray bufStderr;

    QQueue<QByteArray> stdinBuf;

    QSocketNotifier *notifierStdin;
    QSocketNotifier *notifierStdout;
    QSocketNotifier *notifierStderr;

    ssize_t stdinBufRead;
    QProc *proc;

    bool exitValuesCalculated;
    bool socketReadCalled;

    static QProcessManager *procManager;
};


class QProc
{
public:
    QProc( pid_t p, QProcess *proc=0 ) : pid(p), process(proc)
    {
#if defined(QT_QPROCESS_DEBUG)
	qDebug( "QProc: Constructor for pid %d and QProcess %p", pid, process );
#endif
	socketStdin = 0;
	socketStdout = 0;
	socketStderr = 0;
    }
    ~QProc()
    {
#if defined(QT_QPROCESS_DEBUG)
	qDebug( "QProc: Destructor for pid %d and QProcess %p", pid, process );
#endif
	if ( process != 0 ) {
	    if ( process->d->notifierStdin )
	      process->d->notifierStdin->setEnabled( FALSE );
	    if ( process->d->notifierStdout )
		process->d->notifierStdout->setEnabled( FALSE );
	    if ( process->d->notifierStderr )
		process->d->notifierStderr->setEnabled( FALSE );
	    process->d->proc = 0;
	}
	if( socketStdin != 0 )
	  ::close( socketStdin );
	// ### close these sockets even on parent exit or is it better only on
	// sigchld (but what do I have to do with them on exit then)?
	if( socketStdout != 0 )
	    ::close( socketStdout );
	if( socketStderr != 0 )
	    ::close( socketStderr );
    }

    pid_t pid;
    int socketStdin;
    int socketStdout;
    int socketStderr;
    QProcess *process;
};


/***********************************************************************
 *
 * QProcessManager
 *
 **********************************************************************/
class QProcessManager : public QObject
{
    Q_OBJECT

public:
    QProcessManager();
    ~QProcessManager();

    void append( QProc *p );
    void remove( QProc *p );

    void cleanup();

public slots:
    void removeMe();
    void sigchldHnd( int );

public:
    struct sigaction oldactChld;
    struct sigaction oldactPipe;
    QList<QProc> *procList;
    int sigchldFd[2];
};

#endif //QPROCESS_UNIX_H

