/****************************************************************************
** Meta object code from reading C++ file 'mainWin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainWin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_qttest_t {
    QByteArrayData data[8];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qttest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qttest_t qt_meta_stringdata_qttest = {
    {
QT_MOC_LITERAL(0, 0, 6), // "qttest"
QT_MOC_LITERAL(1, 7, 16), // "OpenImageClicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "pictureCapture"
QT_MOC_LITERAL(4, 40, 9), // "nextframe"
QT_MOC_LITERAL(5, 50, 9), // "selectpic"
QT_MOC_LITERAL(6, 60, 5), // "train"
QT_MOC_LITERAL(7, 66, 11) // "updateplain"

    },
    "qttest\0OpenImageClicked\0\0pictureCapture\0"
    "nextframe\0selectpic\0train\0updateplain"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qttest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void qttest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        qttest *_t = static_cast<qttest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OpenImageClicked(); break;
        case 1: _t->pictureCapture(); break;
        case 2: _t->nextframe(); break;
        case 3: _t->selectpic(); break;
        case 4: _t->train(); break;
        case 5: _t->updateplain(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject qttest::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qttest.data,
      qt_meta_data_qttest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *qttest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qttest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_qttest.stringdata0))
        return static_cast<void*>(const_cast< qttest*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qttest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
