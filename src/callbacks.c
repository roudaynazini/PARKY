#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "gererParking.h"
#include "agentParking1.h"

char filenameParking[] = "parkings.txt";
char filenameAgentParking1[] = "agentParking1.txt";
int checkSecuriteAjoutParking=1;
int checkSecuriteModifParking=1;
int radioTarifAjoutParking = 1;
int radioTarifModifParking = 1;
void
on_treeviewParkingHome_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonAjouterParkingW_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *windowParkingAjout,*windowParkingHome;
     windowParkingHome = lookup_widget(button,"windowParkingHome");
      
     windowParkingAjout = lookup_widget(button,"windowParkingAjout");
     windowParkingAjout = create_windowParkingAjout();
     gtk_widget_show(windowParkingAjout);
     gtk_widget_destroy(windowParkingHome);
}


void
on_buttonModifierParkingW_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *windowParkingModif,*windowParkingHome;
     windowParkingHome = lookup_widget(button,"windowParkingHome");
      
     windowParkingModif = lookup_widget(button,"windowParkingModif");
     windowParkingModif = create_windowParkingModif();
     gtk_widget_show(windowParkingModif);
     gtk_widget_destroy(windowParkingHome);
}


void
on_buttonSupprimerParkingW_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *windowParkingSup,*windowParkingHome;
     windowParkingHome = lookup_widget(button,"windowParkingHome");
      
     windowParkingSup = lookup_widget(button,"windowParkingSup");
     windowParkingSup = create_windowParkingSup();
     gtk_widget_show(windowParkingSup);
     gtk_widget_destroy(windowParkingHome);
}


void
on_buttonActualiserParkingW_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowParkingHome,*w1,*treeview;
      w1=lookup_widget(button,"windowParkingHome");
      windowParkingHome=create_windowParkingHome();
       gtk_widget_show(windowParkingHome);
       gtk_widget_hide(w1);
       treeview=lookup_widget(windowParkingHome,"treeviewParkingHome");
       viderParking(treeview);
       afficherParking(treeview,filenameParking);

}


void
on_buttonStatistiqueParkingW_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *windowParkingAffectation,*windowParkingHome;
     windowParkingHome = lookup_widget(button,"windowParkingHome");
      
     windowParkingAffectation = lookup_widget(button,"windowParkingAffectation");
     windowParkingAffectation = create_windowParkingAffectation();
     gtk_widget_show(windowParkingAffectation);
    // gtk_widget_destroy(windowParkingHome);
}


void
on_buttonRechercheParking_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *nom,*pInfo,*windowParkingHome,*w1,*treeview;
       int b = 1;
       char nom1[50];
       windowParkingHome = lookup_widget(button,"windowParkingHome");
       windowParkingHome = create_windowParkingHome();
       nom = lookup_widget(button,"ParkingSearchTextField");
       strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(nom)));
     
       if(strcmp(nom1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
       switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
       }else{

         
       w1=lookup_widget(button,"windowParkingHome");
       windowParkingHome=create_windowParkingHome();
       gtk_widget_show(windowParkingHome);
       gtk_widget_hide(w1);
       treeview=lookup_widget(windowParkingHome,"treeviewParkingHome");
       viderParking(treeview);
       afficherParkingByID(treeview,filenameParking,nom1);
}
}


void
on_buttonFiltreParking_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

       GtkWidget *nom,*pInfo,*windowParkingHome,*w1,*treeview;
       int b = 1;
       char nom1[50];
       windowParkingHome = lookup_widget(button,"windowParkingHome");
       windowParkingHome = create_windowParkingHome();
       nom = lookup_widget(button,"ParkingFiltreTextField");
       strcpy(nom1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(nom)));
     
       if(strcmp(nom1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
       switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
       }else{

         
       w1=lookup_widget(button,"windowParkingHome");
       windowParkingHome=create_windowParkingHome();
       gtk_widget_show(windowParkingHome);
       gtk_widget_hide(w1);
       treeview=lookup_widget(windowParkingHome,"treeviewParkingHome");
       viderParking(treeview);
       afficherParkingByAdresse(treeview,filenameParking,nom1);
}
}


void
on_buttonReturnMenuParking_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_btnSupParking_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id ,*windowParkingSup,*windowParkingHome,*labelControl,*pInfo;
    // initialisation de varibale de controlle saisie
       int b = 1;
	char id1[50];
   // declaration de notre struct 
      
       // declaration des variables 
 	windowParkingHome = lookup_widget(button,"windowParkingHome");
 	windowParkingSup = lookup_widget(button,"windowParkingSup");
 	id = lookup_widget(button,"textIdSupParking");
 	
 	labelControl = lookup_widget(button,"textIdSupParkingControl");
 	
 	  // recuperation des information d apres interfaces graphique 
            // recuperation de textField
     strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          // recuperation de combobox
  
           

        // controlle saisie 
        if(strcmp(id1,"")==0 ){
            
           b=0;
             }
         

     //  ajouter et logique de programme 

          if (b == 0){
         

               gtk_label_set_text(GTK_LABEL(labelControl),"  ⚠️ Erreur : Veuillez vérifier vos données et réessayer. ");



         }else{
          if(!isExistParkingById(filenameParking,id1)){
              gtk_label_set_text(GTK_LABEL(labelControl),"  ⚠️ Id Introuvable , il n existe pas ... ");

	   }else{
       int t =  supprimerParking(filenameParking,id1);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"✅ Votre élément a été Suppression avec succès !");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                     
                   gtk_label_set_text(GTK_LABEL(labelControl),"");
                
          		 
              
             windowParkingHome = create_windowParkingHome();
             gtk_widget_show(windowParkingHome);
              gtk_widget_destroy(windowParkingSup);
                 
       
               break;


          }
       }else{

   


         gtk_label_set_text(GTK_LABEL(labelControl),"❌ Une erreur est survenue lors de l'Suppression de l'élément. Veuillez réessaye  ");

      }
}
}
}


void
on_btnCancelSupParking_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *windowParkingSup,*windowParkingHome;
     windowParkingHome = lookup_widget(button,"windowParkingHome");
      
     windowParkingSup = lookup_widget(button,"windowParkingSup");
     windowParkingHome = create_windowParkingHome();
     gtk_widget_show(windowParkingHome);
     gtk_widget_destroy(windowParkingSup);
}


void
on_checkSecNonAjoutParking_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 {checkSecuriteAjoutParking=2;}
}


void
on_checkSecOuiAjoutParking_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
 {checkSecuriteAjoutParking=1;}
}


void
on_radioHoraireAjoutParking_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
 {radioTarifAjoutParking=1;}
}


void
on_radioJournalierAjoutParking_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
 {radioTarifAjoutParking=2;}
}


void
on_btnAjoutParking_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *id ,*nom,*adresse,*capacite,*tarif,*windowParkingAjout,*windowParkingHome,*labelControl,*pInfo;
   // initialisation de varibale de controlle saisie
       int b = 1;
   // declaration de notre struct 
       Parking r;
     // declaration des variables 
        windowParkingHome = lookup_widget(button,"windowParkingHome");
 	windowParkingAjout = lookup_widget(button,"windowParkingAjout");
        
        id = lookup_widget(button,"textIdAjoutParking");
         nom = lookup_widget(button,"textNomAjoutParking");
         adresse = lookup_widget(button,"comboAdresseAjoutParking");
         capacite = lookup_widget(button,"spinCapaciteAjoutParking");
	tarif = lookup_widget(button,"spinTarifAjoutParking");
	labelControl = lookup_widget(button,"windowParkingAjoutControl");
           // recuperation des information d apres interfaces graphique 
            // recuperation de textField
    	 strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));
         strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
          // recuperation de combobox
     	strcpy(r.adresse,gtk_combo_box_get_active_text(GTK_COMBO_BOX(adresse)));
        // recuperation de spinButton
    	 r.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capacite));
         r.tarif =(float) gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tarif));
         r.placeDisponible = r.capacite;

	// recuperation de radio button 
        if(radioTarifAjoutParking == 1){


          strcpy(r.Type_tarifaire,"horaire");
        }else if(radioTarifAjoutParking == 2){

          strcpy(r.Type_tarifaire,"journalier");
       }

        // recuperation de check box 
      if(checkSecuriteAjoutParking == 1){
          strcpy(r.securite_disponible,"oui");
      }else if(checkSecuriteAjoutParking ==2){
          strcpy(r.securite_disponible,"non");
      }

      // controlle saisie 
        if(strcmp(r.id,"")==0 ){
            
           b=0;
             }


           if(strcmp(r.nom,"")==0 ){
           b=0;
             }
            if(strcmp(r.adresse,"")==0 ){
            
           b=0;
             }
	/*	 if(strcmp(r.Type_tarifaire,"")==0 ){
            
           b=0;
             }

             	 if(strcmp(r.securite_disponible,"")==0 ){
            
           b=0;
             }*/
     
    
          
        //  ajouter et logique de programme 

          if (b == 0){
         

               gtk_label_set_text(GTK_LABEL(labelControl),"  ⚠️ Erreur : Veuillez vérifier vos données et réessayer. ");



         }else{
           if(isExistParkingById("parkings.txt",r.id)){
              gtk_label_set_text(GTK_LABEL(labelControl),"  ⚠️ Id existe deja ... ");

	   }else{

         
       int t =  ajouterParking("parkings.txt",r);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"✅ Votre élément a été ajouté avec succès !");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                      gtk_entry_set_text(GTK_ENTRY(nom),"");
			
                   gtk_label_set_text(GTK_LABEL(labelControl),"");
                
          		 
              
             windowParkingHome = create_windowParkingHome();
             gtk_widget_show(windowParkingHome);
              gtk_widget_destroy(windowParkingAjout);
                 
       
               break;


          }
       }else{

   


         gtk_label_set_text(GTK_LABEL(labelControl),"❌ Une erreur est survenue lors de l'ajout de l'élément. Veuillez réessaye  ");

      }

   }
}



        
}


void
on_btnCancelAjoutParking_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *windowParkingAjout,*windowParkingHome;
     windowParkingHome = lookup_widget(button,"windowParkingHome");
      
     windowParkingAjout = lookup_widget(button,"windowParkingAjout");
     windowParkingHome = create_windowParkingHome();
     gtk_widget_show(windowParkingHome);
     gtk_widget_destroy(windowParkingAjout);
}


void
on_buttonParkinghercheRecModif_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *id ,*nom,*adresse,*capacite,*tarif,*horaire,*journalier,*oui,*non,*windowParkingModif,*windowParkingHome,*labelControl,*pInfo;
   // initialisation de varibale de controlle saisie
       int b = 1;
   // declaration de notre struct 
       Parking r;
  char id1[50];
     // declaration des variables 
        windowParkingHome = lookup_widget(button,"windowParkingHome");
 	windowParkingModif = lookup_widget(button,"windowParkingModif");
        
        id = lookup_widget(button,"textIdModifParking");
         nom = lookup_widget(button,"textNomModifParking");
         adresse = lookup_widget(button,"comboAdresseModifParking");
         capacite = lookup_widget(button,"spinCapaciteModifParking");
	tarif = lookup_widget(button,"spinTarifModifParking");
	labelControl = lookup_widget(button,"windowParkingModifControl");
        horaire = lookup_widget(button,"radioHoraireModifParking");
        journalier = lookup_widget(button,"radioJournalierModifParking");
        oui = lookup_widget(button,"checkSecOuiModifParking");
        non = lookup_widget(button,"checkSecNonModifParking");

                  // recuperation de textField
     strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));


                // controlle saisie 
        if(strcmp(id1,"")==0 ){
            
           b=0;
             }


     
                   if(b==0){
            gtk_label_set_text(GTK_LABEL(labelControl),"  ⚠️ Erreur : Veuillez vérifier vos données et réessayer. ");
          }else{
          if(!isExistParkingById(filenameParking,id1)){
              gtk_label_set_text(GTK_LABEL(labelControl),"  ⚠️ Id Introuvable , il n existe pas ... ");

	   }else{
		r = chercherParkingById(filenameParking,id1);
                
               gtk_entry_set_text(GTK_ENTRY(id),r.id);
		  gtk_entry_set_text(GTK_ENTRY(nom),r.nom);
		gtk_combo_box_set_active(GTK_COMBO_BOX(adresse),1);
                gtk_spin_button_set_value(capacite, r.capacite);
                gtk_spin_button_set_value(tarif,r.tarif);
              
                  
                 

		// Set Radio Button Value
                if(strcmp(r.Type_tarifaire,"horaire")==0){
		gtk_toggle_button_set_active(GTK_RADIO_BUTTON(horaire),TRUE);
		}else if(strcmp(r.Type_tarifaire,"journalier")==0){
		gtk_toggle_button_set_active(GTK_RADIO_BUTTON(journalier),TRUE);
		}
		
            
		 // Set check Button Value
                   if(strcmp(r.securite_disponible,"oui")==0){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(oui),TRUE);
		}else if(strcmp(r.securite_disponible,"non")==0){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(non),TRUE);
		}

               
           }

}
         
}


void
on_checkSecNonModifParking_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
 {checkSecuriteModifParking=2;}
}


void
on_checkSecOuiModifParking_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
 {checkSecuriteModifParking=1;}
}


void
on_radioHoraireModifParking_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
 {radioTarifModifParking=1;}
}


void
on_radioJournalierModifParking_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
 {radioTarifModifParking=2;}
}


void
on_btnModifParking_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *id ,*nom,*adresse,*capacite,*tarif,*windowParkingModif,*windowParkingHome,*labelControl,*pInfo;
   // initialisation de varibale de controlle saisie
       int b = 1;
   // declaration de notre struct 
       Parking r;
     // declaration des variables 
        windowParkingHome = lookup_widget(button,"windowParkingHome");
 	windowParkingModif = lookup_widget(button,"windowParkingModif");
        
        id = lookup_widget(button,"textIdModifParking");
         nom = lookup_widget(button,"textNomModifParking");
         adresse = lookup_widget(button,"comboAdresseModifParking");
         capacite = lookup_widget(button,"spinCapaciteModifParking");
	tarif = lookup_widget(button,"spinTarifModifParking");
	labelControl = lookup_widget(button,"windowParkingModifControl");
           // recuperation des information d apres interfaces graphique 
            // recuperation de textField
    	 strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));
         strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
          // recuperation de combobox
     	strcpy(r.adresse,gtk_combo_box_get_active_text(GTK_COMBO_BOX(adresse)));
        // recuperation de spinButton
    	 r.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capacite));
         r.tarif =(float) gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tarif));
         r.placeDisponible = r.capacite;

	// recuperation de radio button 
        if(radioTarifModifParking == 1){


          strcpy(r.Type_tarifaire,"horaire");
        }else if(radioTarifModifParking == 2){

          strcpy(r.Type_tarifaire,"journalier");
       }

        // recuperation de check box 
      if(checkSecuriteModifParking == 1){
          strcpy(r.securite_disponible,"oui");
      }else if(checkSecuriteModifParking ==2){
          strcpy(r.securite_disponible,"non");
      }

      // controlle saisie 
        if(strcmp(r.id,"")==0 ){
            
           b=0;
             }
           if(strcmp(r.nom,"")==0 ){
           b=0;
             }
            if(strcmp(r.adresse,"")==0 ){
            
           b=0;
             }
	/*	 if(strcmp(r.Type_tarifaire,"")==0 ){
            
           b=0;
             }

             	 if(strcmp(r.securite_disponible,"")==0 ){
            
           b=0;
             }*/
     
        //  ajouter et logique de programme 

       
          if (b == 0){
         

               gtk_label_set_text(GTK_LABEL(labelControl),"  ⚠️ Erreur : Veuillez vérifier vos données et réessayer. ");



         }else{
           if(!isExistParkingById(filenameParking,r.id)){
              gtk_label_set_text(GTK_LABEL(labelControl)," ⚠️ Id Introuvable , il n existe pas ... ");

	   }else{

         
       int t =  modifierParking(filenameParking,r.id,r);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"✅ Votre élément a été modifié avec succès !");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                       gtk_entry_set_text(GTK_ENTRY(nom),"");
			
                   gtk_label_set_text(GTK_LABEL(labelControl),"");
                
          		 
              
             windowParkingHome = create_windowParkingHome();
             gtk_widget_show(windowParkingHome);
              gtk_widget_destroy(windowParkingModif);
                 
       
               break;


          }
       }else{

   


         gtk_label_set_text(GTK_LABEL(labelControl),"❌ Une erreur est survenue lors de l'ajout de l'élément. Veuillez réessaye  ");

      }

   }
}
}


void
on_btnCancelModifParking_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *windowParkingModif,*windowParkingHome;
     windowParkingHome = lookup_widget(button,"windowParkingHome");
      
     windowParkingModif = lookup_widget(button,"windowParkingModif");
     windowParkingHome = create_windowParkingHome();
     gtk_widget_show(windowParkingHome);
     gtk_widget_destroy(windowParkingModif);
}


void
on_btnAffectationParking_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *idPar,*idAge ,*windowParkingAffectation,*windowParkingHome,*labelControl,*pInfo;
    // initialisation de varibale de controlle saisie
       int b = 1;
	char idParking[50];
	char idAgent[50];
      
       // declaration des variables 
 	windowParkingHome = lookup_widget(button,"windowParkingHome");
 	windowParkingAffectation = lookup_widget(button,"windowParkingAffectation");
 	idPar = lookup_widget(button,"comboIdParkingAffectParking");
 	idAge = lookup_widget(button,"comboIdAgentAffectParking");
 	labelControl = lookup_widget(button,"textIdAffectationParkingControl");
        // recuperation des donne
         strcpy(idParking,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idPar)));
         strcpy(idAgent,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idAge)));

           // controlle saisie 
        if(strcmp(idParking,"")==0 ){
            
           b=0;
             }

        if(strcmp(idAgent,"")==0 ){
            
           b=0;
             }
         
         //  ajouter et logique de programme 

          if (b == 0){
         

               gtk_label_set_text(GTK_LABEL(labelControl),"  ⚠️  Veuillez vérifier vos données ");



         }else{
     
       int t =  affecterAagent1(filenameAgentParking1,idAgent,idParking);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"✅ Votre élément a été Suppression avec succès !");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                
                     
                   gtk_label_set_text(GTK_LABEL(labelControl),"");
                
          		 
              
             windowParkingHome = create_windowParkingHome();
             gtk_widget_show(windowParkingHome);
              gtk_widget_destroy(windowParkingAffectation);
                 
       
               break;


          }
       }else{

   


         gtk_label_set_text(GTK_LABEL(labelControl),"❌ Une erreur est survenue  ");

      }
}


}


void
on_btnCancelAffectationParking_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *windowParkingAffectation,*windowParkingHome;
     windowParkingHome = lookup_widget(button,"windowParkingHome");
      
     windowParkingAffectation = lookup_widget(button,"windowParkingAffectation");
     windowParkingHome = create_windowParkingHome();
     gtk_widget_show(windowParkingHome);
     gtk_widget_destroy(windowParkingAffectation);
}

