#!/bin/sh

rm proc_table.dat
export QUERY_STRING="model_list=eggs"

do_create.cgi 

if !(grep eggs.pml proc_table.dat)
then
  echo
  echo Failed create process.
  echo
fi