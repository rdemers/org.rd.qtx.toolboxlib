#-------------------------------------------------
#
# Project solution created by R. Demers 2015-06-24
#
#-------------------------------------------------

TEMPLATE = subdirs

SUBDIRS += QtxToolboxLib \
           QtxToolboxTest \
           QtxToolboxDemo

QtxToolboxDemo.depends = QtxToolboxLib
QtxToolboxTest.depends = QtxToolboxLib
