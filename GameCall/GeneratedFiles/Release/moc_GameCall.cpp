/****************************************************************************
** Meta object code from reading C++ file 'GameCall.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GameCall.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameCall.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameCall_t {
    QByteArrayData data[15];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameCall_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameCall_t qt_meta_stringdata_GameCall = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GameCall"
QT_MOC_LITERAL(1, 9, 8), // "commingc"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 14), // "QList<QString>"
QT_MOC_LITERAL(4, 34, 4), // "data"
QT_MOC_LITERAL(5, 39, 4), // "exec"
QT_MOC_LITERAL(6, 44, 11), // "pidFreshBtn"
QT_MOC_LITERAL(7, 56, 8), // "aboutBtn"
QT_MOC_LITERAL(8, 65, 16), // "changeWinSizeBtn"
QT_MOC_LITERAL(9, 82, 15), // "freshWinSizeBtn"
QT_MOC_LITERAL(10, 98, 7), // "callBtn"
QT_MOC_LITERAL(11, 106, 11), // "callSignBtn"
QT_MOC_LITERAL(12, 118, 17), // "listDoubleclicked"
QT_MOC_LITERAL(13, 136, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(14, 153, 4) // "item"

    },
    "GameCall\0commingc\0\0QList<QString>\0"
    "data\0exec\0pidFreshBtn\0aboutBtn\0"
    "changeWinSizeBtn\0freshWinSizeBtn\0"
    "callBtn\0callSignBtn\0listDoubleclicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameCall[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   62,    2, 0x0a /* Public */,
       6,    0,   65,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,
      11,    0,   70,    2, 0x0a /* Public */,
      12,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void GameCall::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameCall *_t = static_cast<GameCall *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commingc((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 1: _t->exec((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 2: _t->pidFreshBtn(); break;
        case 3: _t->aboutBtn(); break;
        case 4: _t->changeWinSizeBtn(); break;
        case 5: _t->freshWinSizeBtn(); break;
        case 6: _t->callBtn(); break;
        case 7: _t->callSignBtn(); break;
        case 8: _t->listDoubleclicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameCall::*_t)(QList<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameCall::commingc)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GameCall::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GameCall.data,
      qt_meta_data_GameCall,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameCall::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameCall::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameCall.stringdata0))
        return static_cast<void*>(const_cast< GameCall*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GameCall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GameCall::commingc(QList<QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
