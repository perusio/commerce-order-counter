# Commerce Order Counter

## Introduction

**Commerce Order Counter** is a module for
[Drupal Commerce](http://drupalcommerce.org) (or
[Commerce Kickstart](https://drupal.org/project/commerce_kickstart))
that implements a generic framework for having order numbers that are
**independent** of order IDs, which are used for referential integrity
at the schema level. 

The interest of such is for example in invoicing where invoices are
usually obliged to have a sequential numbering scheme. This module
defines `CommerceOrderCounterInterface` that allows you to
define your own numbering system in a clean and simple way.

## Commerce Order Counter Basic

This is a companion module to `commerce_order_counter` that implements
a basic **sequential** integer order counter.
