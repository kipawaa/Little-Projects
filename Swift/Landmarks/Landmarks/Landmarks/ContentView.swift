//
//  ContentView.swift
//  Landmarks
//
//  Created by River McCubbin on 2022-02-23.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack(alignment: .leading) {
            Text("Kipawa River")
                .font(.title)
                .foregroundColor(Color.red)
                
            HStack {
                Text("Parc National d'Opémican")
                    .font(.subheadline)
                    .foregroundColor(.black)
                
                Spacer()
                
                Text("Laniel, Quebec")
                    .font(.subheadline)
                    .foregroundColor(.black)
            }
        }
        .padding()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
