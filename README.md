# Kernel-Module

Το συγκεκριμένο project πραγματοποιήθηκε στα πλαίσια του μαθήματος "Λειτουργικά Συστήματα" του τμήματος Ηλεκτρολόγων Μηχανικών και Τεχνολογίας Υπολογιστών του Πανεπιστημίου Πατρών.

Εγκαταστείστε ένα VirtualBox με linux, αν δουλεύετε σε windows.
Ανοίξτε το terminal και εκτελέστε τις παρακάτω εντολές:
-> sudo apt-get update
-> sudo apt-get upgrade
-> sudo apt-get install build-essential kmod
-> sudo apt-get install linux-headers-'uname -r'

Για να μεταγλωττίσετε κάθε module, ανοίγετε ένα terminal στα path τους και εκτελείτε την εντολή make.
Σημείωση: Με την εντολή make clean διαγράφετε τα αρχεία που δημιουργήθηκαν με το make.
Μπορείτε να δείτε τις πληροφορίες των module με την εντολή modinfo module_name.ko

Στην συνέχεια για να φορτώσουμε το module στο σύστημα, ακολουθούμε την παρακάτω διαδικασία:
1) sudo insmod module_name.ko
2) sudo rmmod module_name (αφαιρεί το module)
3) journalctl --since "10 minutes ago" | grep kernel (ελέγχει τα logs του συστήματος τα τελευταία 10 λεπτά και τυπώνει τα μηνύματα των συναρτήσεων εισόδου-εξόδου)
