/****************************************************************************
** Meta object code from reading C++ file 'OpenEval.h'
**
** Created: Wed Nov 28 11:55:05 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Source/OpenEval.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenEval.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OpenEval[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      24,    9,    9,    9, 0x0a,
      38,    9,    9,    9, 0x0a,
      56,    9,    9,    9, 0x0a,
      78,    9,    9,    9, 0x0a,
     100,    9,    9,    9, 0x0a,
     118,    9,    9,    9, 0x0a,
     130,    9,    9,    9, 0x0a,
     147,    9,    9,    9, 0x0a,
     166,    9,    9,    9, 0x0a,
     185,    9,    9,    9, 0x0a,
     200,    9,    9,    9, 0x0a,
     215,    9,    9,    9, 0x0a,
     230,    9,    9,    9, 0x0a,
     245,    9,    9,    9, 0x0a,
     262,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OpenEval[] = {
    "OpenEval\0\0addEmployee()\0addEmployer()\0"
    "setNextEmployee()\0setPreviousEmployee()\0"
    "setPreviousEmployer()\0setNextEmployer()\0"
    "setFields()\0reviewEmployee()\0"
    "showEmployerInfo()\0showEmployeeInfo()\0"
    "editEmployee()\0editEmployer()\0"
    "findEmployee()\0findEmployer()\0"
    "removeEmployee()\0removeEmployer()\0"
};

void OpenEval::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OpenEval *_t = static_cast<OpenEval *>(_o);
        switch (_id) {
        case 0: _t->addEmployee(); break;
        case 1: _t->addEmployer(); break;
        case 2: _t->setNextEmployee(); break;
        case 3: _t->setPreviousEmployee(); break;
        case 4: _t->setPreviousEmployer(); break;
        case 5: _t->setNextEmployer(); break;
        case 6: _t->setFields(); break;
        case 7: _t->reviewEmployee(); break;
        case 8: _t->showEmployerInfo(); break;
        case 9: _t->showEmployeeInfo(); break;
        case 10: _t->editEmployee(); break;
        case 11: _t->editEmployer(); break;
        case 12: _t->findEmployee(); break;
        case 13: _t->findEmployer(); break;
        case 14: _t->removeEmployee(); break;
        case 15: _t->removeEmployer(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OpenEval::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OpenEval::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OpenEval,
      qt_meta_data_OpenEval, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OpenEval::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OpenEval::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OpenEval::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OpenEval))
        return static_cast<void*>(const_cast< OpenEval*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OpenEval::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
