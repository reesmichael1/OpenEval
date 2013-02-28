/****************************************************************************
** Meta object code from reading C++ file 'FindEmployee.h'
**
** Created: Thu Feb 28 07:55:42 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Source/FindEmployee.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FindEmployee.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FindEmployee[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      29,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FindEmployee[] = {
    "FindEmployee\0\0findEmployee()\0cancel()\0"
};

void FindEmployee::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FindEmployee *_t = static_cast<FindEmployee *>(_o);
        switch (_id) {
        case 0: _t->findEmployee(); break;
        case 1: _t->cancel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FindEmployee::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FindEmployee::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FindEmployee,
      qt_meta_data_FindEmployee, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FindEmployee::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FindEmployee::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FindEmployee::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FindEmployee))
        return static_cast<void*>(const_cast< FindEmployee*>(this));
    return QDialog::qt_metacast(_clname);
}

int FindEmployee::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
