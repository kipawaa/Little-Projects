//
//  Vectors.swift
//  Vector Field
//
//  Created by River McCubbin on 2024-01-24.
//

import Foundation
import ScreenSaver

import ScreenSaver

class VectorView: ScreenSaverView {

    // MARK: - Initialization

    override init?(frame: NSRect, isPreview: Bool) {
        super.init(frame: frame, isPreview: isPreview)
    }

    @available(*, unavailable)
    required init?(coder decoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    // MARK: - Lifecycle

    override func draw(_ rect: NSRect) {
        // Draw a single frame in this function
        
    }

    override func animateOneFrame() {
        super.animateOneFrame()

        // Update the "state" of the screensaver in this function
    }

}
