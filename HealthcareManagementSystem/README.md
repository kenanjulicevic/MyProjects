# Healthcare Management System

Console-based C++ application for managing a healthcare facility's operations, including patient records, medical staff, services, and appointment scheduling.

## Features

- **Patient Management** — Register, view, edit, and delete patient records with full health card data (diagnosis, allergies, birth year)
- **Staff Management** — Register and manage doctors and other medical staff with salary tracking
- **Service Catalog** — Create and manage available medical services with pricing
- **Appointment Scheduling** — Book, edit, view, and cancel appointments with duplicate-time validation
- **Search & Filter** — Look up patients, doctors, and staff by JMBG (unique personal ID) or health card number
- **Admin Panel** — Password-protected admin menu for full CRUD operations on staff, services, and more
- **Multi-role Access** — Separate menus for patients, doctors, and administrators

## Classes

| Class | Purpose |
|-------|---------|
| `Osoba` | Base class for all persons (name, surname, JMBG) |
| `Pacijent` | Patient inheriting from Osoba, with health card data |
| `Radnici` | General staff member with salary |
| `Doktori` | Doctor with salary |
| `ZdravstveniKarton` | Health card: birth year, diagnosis, allergies |
| `Usluge` | Medical services with name and price |
| `Termini` | Appointments linking a patient's health card to a time slot |

## Building & Running

```bash
g++ healthcare_management_system.cpp -o healthcare
./healthcare
