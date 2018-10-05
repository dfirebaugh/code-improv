import webbrowser
class Movie():
    
    def __init__(self, movie_title, movie_poster_image, movie_storyline, movie_trailer_url):
        
        
        '''This function contains the following details of the movie:
        Arguments:
        self:It points to a specific movie, ie.the current instance
        movie_title: the movie title
        movie_poster_image:is the poster image url
        movie_storyline: the movie story line
        movie_trailer_url: the youtube trailer url of that particular movie'''


        self.title=movie_title
        self.poster_image_url=movie_poster_image
        self.storyline= movie_storyline
        self.trailer_url=movie_trailer_url      


def show_trailer(self):
        
        '''This function is used to play the trailer of the movie
        Arguments:
        self:It points to the movie whose trailer has to played'''


        webbrowser.open(self.trailer_url)
