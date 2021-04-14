ChooseFlight()
{
	 tName = "05.Create_ticket_ChooseCost";
     lr_start_transaction(tName);
 

	 for(i=1;i<=elemCnt;i++){
    	  	sprintf(arrayPrice, "{priceTicket_%d}", i);
    	  	cost =atoi(lr_eval_string(arrayPrice));
    	  	lr_output_message("%d",cost);
	    	  	if ((cost%2)==0) {
					
				    sprintf(arrayCheck, "{Radio_%d}", i); 
				    check = lr_eval_string(arrayCheck);
				    lr_output_message ("Цена билета %d: %d $.\n\t--------------------", i, cost);
							
					checkForChoose=check;
					lr_output_message("%s",checkForChoose);
					lr_output_message("Выбран рейс: %d \n\t--------------------", cost);
					lr_save_string(checkForChoose,"checked");
				
//				
//					web_submit_form("Check Radio", 
//						    ITEMDATA,
//						    "name=checked", "value=checked", ENDITEM,
//						   
//						    LAST );
					
				    	    
		    	  	} else {
		    	  	countTick+=1;
		    	  	}    
	       
	}
 
	lr_output_message("%d",countTick);
	
	if(countTick==4) {
 	
		vuser_end();
		
	}
    	  	 	  	
  
 
 	
    
    lr_output_message("%s",checkForChoose);
 
	 status=web_submit_data("reservations.pl_2", 
	  "Action={Host}/cgi-bin/reservations.pl", 
	  "Method=POST", 
	  "TargetFrame=", 
	  "RecContentType=text/html", 
	  "Referer={Host}/cgi-bin/reservations.pl", 
	  "Snapshot=t15.inf", 
	  "Mode=HTML", 
	  ITEMDATA, 
	 
	  "Name=OFlight", "Value={checked}", ENDITEM, 
	
	  "Name=numPassengers", "Value=1", ENDITEM, 
	  "Name=advanceDiscount", "Value=0", ENDITEM, 
	  "Name=seatType", "Value={TypePref}", ENDITEM, 
	  "Name=seatPref", "Value={SeatPref}", ENDITEM, 
	  "Name=reserveFlights.x", "Value=73", ENDITEM, 
	  "Name=reserveFlights.y", "Value=13", ENDITEM, 
	  LAST);
 
 end_transaction(tName, status); 
 //lr_think_time(4);
 
	return 0;
}
