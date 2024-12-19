#include <gtk/gtk.h>


void
on_treeviewParkingHome_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonAjouterParkingW_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifierParkingW_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimerParkingW_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonActualiserParkingW_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonStatistiqueParkingW_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRechercheParking_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonFiltreParking_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonReturnMenuParking_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnSupParking_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnCancelSupParking_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkSecNonAjoutParking_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkSecOuiAjoutParking_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioHoraireAjoutParking_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioJournalierAjoutParking_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_btnAjoutParking_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnCancelAjoutParking_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonParkinghercheRecModif_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkSecNonModifParking_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkSecOuiModifParking_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioHoraireModifParking_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioJournalierModifParking_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_btnModifParking_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnCancelModifParking_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnAffectationParking_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnCancelAffectationParking_clicked (GtkButton       *button,
                                        gpointer         user_data);
