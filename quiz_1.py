import media
import fresh_tomatoes


# Instance interstellar of movie class
interstellar = media.Movie("Interstellar","http://t1.gstatic.com/images?q=tbn:ANd9GcRf61mker2o4KH3CbVE7Zw5B1-VogMH8LfZHEaq3UdCMLxARZAB","it is about some people who travel through space to save the earth","https://www.youtube.com/watch?v=zSWdZVtXT7E")

# Instance need for speed of movie class
need_for_speed = media.Movie("Need for Speed","http://t2.gstatic.com/images?q=tbn:ANd9GcS_hoRU2hxj7QsqhEuwKSGD1e-sm4WuOrgZdLAy3nKMq8yVw-S7","it is about a man who races to clear his name from a crime and win his reputation back","https://www.youtube.com/watch?v=fsrJWUVoXeM")

# Instance avatar of movie class
avatar = media.Movie("Avatar","http://t0.gstatic.com/images?q=tbn:ANd9GcQCfmvrE4fMo2cd8esc7mDZPtFSJThAujddMPkRtti1_ij6u-jp","A hybrid human-alien called an Avatar is created to facilitate communication with the indigenous Na'vis from the planet Pandora","https://www.youtube.com/watch?v=5PSNL1qE6VY")

# Instance deadpool of movie class
deadpool = media.Movie("Deadpool","http://t2.gstatic.com/images?q=tbn:ANd9GcTvrIHJfasS6poy34esN1O5hZonXaiqfEZb4WbnbAa9qJCIL8_9","It is about a fast-talking mercenary with a morbid sense of humor","https://www.youtube.com/watch?v=FyKWUTwSYAs")

# Instance zootopia of movie class
zootopia = media.Movie("Zootopia","http://t2.gstatic.com/images?q=tbn:ANd9GcQj1fU0-Idujcrs_MB2xEWbVEygeCkcjYUp4Z-hSIPqgu0vFbQi","a rookie bunny cop and a con-artist fox work together to uncover a conspiracy that puts the lives of predators in danger","https://www.youtube.com/watch?v=jWM0ct-OLsM")

# Instance passengers of movie class
passengers = media.Movie("Passengers","http://t3.gstatic.com/images?q=tbn:ANd9GcQvqid_rbEby5j_XkVnSdwWgvSTiX9Np1I6iTJPJWYZFCBOPe4w","It is about the journey through space of 2 people who get woken up 90 years before the actual date of arrival with no means to go back to cryo-sleep","https://www.youtube.com/watch?v=7BWWWQzTpNU")



# list of movies used as instances of the class movie
films=[interstellar,need_for_speed,avatar,deadpool,zootopia,passengers]

# the list of movies is passed as an argument to the function of the fresh_tomatoes file
fresh_tomatoes.open_movies_page(films)
